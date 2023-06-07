use std::net::SocketAddr;

use crate::App; // since this is coming from lib.rs
                // crate doesn't have much nesting for import usage
use leptos::*;

use axum::{routing::get, Router};

#[tokio::main]
async fn main() {
    let app = Router::new().route(
        "/",
        get(|| async { mount_to_body(|cx| view! { cx, <App /> }) }),
    );

    let localhost_addr = SocketAddr::from(([127, 0, 0, 1], 3000));

    axum::Server::bind(&localhost_addr)
        .serve(app.into_make_service())
        .await
        .unwrap();
}
