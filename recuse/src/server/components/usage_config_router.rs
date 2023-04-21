use axum::{
    extract::Query,
    http::StatusCode,
    response::{Html, IntoResponse},
    routing::{get, get_service, post},
    Json, Router,
};
use serde::{Deserialize, Serialize};
use std::net::SocketAddr;
use tower_http::services::ServeDir;

// the input to our `index_page` handler
#[derive(Debug, Deserialize, Serialize)]
struct QueryParameter {
    query_arguments: Option<String>,
}

// the output to our `index_page` handler
#[derive(Debug, Deserialize, Serialize)]
struct Page {
    id: u64,
    pagename: String,
}

async fn index_page(
    Query(parameters): Query<QueryParameter>,
) -> impl IntoResponse {
    // insert your application logic here
    let page = Page {
        id: 0,
        pagename: parameters.query_arguments.to_owned().unwrap(),
    };

    println!(
        "$=> {:<16} --- Query Sequence & Parameters Handler --- {parameters:?}",
        "HANDLER"
    );

    let pathname = parameters
        .query_arguments
        .as_deref()
        .unwrap_or("HTTP Error Code: 400");

    return Html(format!("{pathname}"));
}

fn root() -> &str { return "/"; }

fn routes_into_router() -> Router {
    Router::new().route(root(), get(index_page))
}

fn nest_service_route() -> Router {
    Router::new().nest_service(root(), get_service(ServeDir::new("./")))
}

#[tokio::main]
async fn main() {
    tracing_subscriber::fmt::init();

    let app_router = Router::new();
    let local_host_address = SocketAddr::from(([127, 0, 0, 1], 3000));

    let all_routes = app_router
        .merge(routes_into_router())
        .fallback_service(nest_service_route());

    tracing::debug!("Listening on: {:?}", local_host_address);
    axum::Server::bind(&local_host_address)
        .serve(app_router.into_make_service())
        .await
        .unwrap();
}
