use axum::{
    http::StatusCode,
    response::IntoResponse,
    routing::{get, post},
    Json, Router,
};
use serde::{Deserialize, Serialize};
use std::net::SocketAddr;

// the input to our `index_page` handler
#[derive(Deserialize)]
struct IndexPage {
    pagename: String,
}

// the output to our `index_page` handler
#[derive(Serialize)]
struct Page {
    id: u64,
    pagename: String,
}

async fn index_page(
    Json(payload): Json<IndexPage>,
) -> (StatusCode, Json<Page>) {
    // insert your application logic here
    let page = Page {
        id: 0,
        pagename: payload.pagename,
    };

    // this will be converted into a JSON response
    // with a status code of `201 Created`
    (StatusCode::CREATED, Json(page))
}

// basic handler that responds with a static string
async fn root() -> &'static str {
    "/"
}

#[tokio::main]
async fn main() {
    tracing_subscriber::fmt::init();
    let app = Router::new();
    let local_host_address = SocketAddr::from(([127, 0, 0, 1], 3000));
    tracing::debug!("Listening on: {:?}", local_host_address);
    axum::Server::bind(&local_host_address)
        .serve(app.into_make_service())
        .await
        .unwrap();
}
