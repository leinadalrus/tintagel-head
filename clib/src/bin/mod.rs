#![allow(dead_code)]
use sqlx::{
    self,
    pool::PoolOptions,
    postgres::{PgConnectOptions, PgPoolOptions},
    Pool, Postgres,
};
use thiserror::Error;
use tokio::time::Instant;

#[derive(Error, Debug, Clone)]
pub enum EErrors {
    #[error("Internal error")]
    Internal(String),
    #[error("{0}")]
    NotFound(String),
    #[error("{0}")]
    InvalidArgument(String),
}

impl std::convert::From<sqlx::migrate::MigrateError> for EErrors {
    fn from(err: sqlx::migrate::MigrateError) -> Self {
        EErrors::Internal(err.to_string())
    }
}

impl std::convert::From<std::num::ParseIntError> for EErrors {
    fn from(err: std::num::ParseIntError) -> Self {
        EErrors::InvalidArgument(err.to_string())
    }
}

impl std::convert::From<sqlx::Error> for EErrors {
    fn from(err: sqlx::Error) -> Self {
        match err {
            sqlx::Error::RowNotFound => EErrors::NotFound("Not found".into()),
            _ => EErrors::Internal(err.to_string()),
        }
    }
}

#[derive(Clone, Debug)]
pub struct DatabaseConfig {
    pub database_url: String,
    pub database_port: u16,
}

impl DatabaseConfig {
    pub fn load() -> Result<DatabaseConfig, EErrors> {
        dotenv::dotenv().ok();

        let database_url = std::env::var("DATABASE_URL")
            .map_err(|_| undefined("DATABASE_URL"))?;

        let database_port = std::env::var("PORT")
            .ok()
            .map_or(Ok(8080), |retval| retval.parse::<u16>())?;

        Ok(DatabaseConfig {
            database_url,
            database_port,
        })
    }

    pub fn init() -> DatabaseConfig {
        dotenv::dotenv().ok();

        let database_url = std::env::var("DATABASE_URL")
            .ok()
            .map_or_else(|| "DATABASE_URL", |_| "DATABASE_URL");

        let database_port =
            std::env::var("PORT").ok().map_or_else(|| 443, |_| 80);

        DatabaseConfig {
            database_url: database_url.to_owned(),
            database_port,
        }
    }
}

pub struct DatabaseHandler {
    database_duration: Instant,
    database_pool: PoolOptions<Postgres>,
    database_config: DatabaseConfig,
}

impl Default for DatabaseHandler {
    fn default() -> Self {
        let database_pool = PgPoolOptions::default();
        let database_config = DatabaseConfig::init();
        return DatabaseHandler {
            database_duration: tokio::time::Instant::now(),
            database_pool,
            database_config,
        };
    }
}

fn undefined(args: &str) -> EErrors {
    EErrors::NotFound(format!("Error: {}", args))
}

pub async fn connect_to_database(
    database_url: &str,
) -> Result<Pool<Postgres>, EErrors> {
    PgPoolOptions::new()
        .max_connections(1)
        .max_lifetime(std::time::Duration::from_secs(300))
        .connect(database_url)
        .await
        .map_err(|err| {
            println!("db: connecting to DB: {}", err);
            err.into()
        })
}

async fn migrate_with_pooling(
    database: &Pool<Postgres>,
) -> Result<(), EErrors> {
    return match sqlx::migrate!("./db/migrations").run(database).await {
        Ok(_) => Ok::<(), EErrors>(()),
        Err(err) => {
            println!("db::migrate: migrating: {}", &err);
            return Err(err.into());
        }
    };
}

#[tokio::main]
pub async fn main(
) -> std::result::Result<(), std::boxed::Box<dyn std::error::Error>> {
    println!("cargo:rerun-if-changed=migrations");
    let database_handler = DatabaseHandler::default();
    let database_pool: &Pool<Postgres> = &PgPoolOptions::connect_lazy_with(
        database_handler.database_pool,
        PgConnectOptions::default(),
    );

    connect_to_database(&database_handler.database_config.database_url).await;
    migrate_with_pooling(database_pool).await;

    Ok(())
}
