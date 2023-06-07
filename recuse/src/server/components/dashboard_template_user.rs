use crate::server::components::dashboard_card_template::DashboardCardView;
use axum::{
    http::StatusCode,
    response::IntoResponse,
    routing::{get, post},
    Json, Router,
};
use leptos::{leptos_dom::ev::SubmitEvent, *};
use regex::Regex;
use serde::{Deserialize, Serialize};
use std::{env, fs, net::SocketAddr};
use web_sys::Event;

// the input to our `dashboard_view` handler
#[derive(Debug, Deserialize, Serialize)]
struct QueryParameter {
    query_arguments: Option<String>,
}

// the output to our `dashboard_view` handler
#[derive(Debug, Deserialize, Serialize)]
struct DashboardTemplate {
    id: u64,
    pagename: String,
}

#[component]
pub fn DashboardTemplating(cx: Scope) -> impl IntoView {
    // axum parameter routing
    // C.R.U.D document data-model
    tracing_subscriber::fmt::init();

    let file_path = env::current_dir();
    let body = fs::read_to_string(file_path)
        .expect("Expected HTML template-engine renders!?");

    let rex = Regex::new(r"/[^\\]*\.(html)$/");
    let mut itemized; // free value for replacing `capts` value

    for capts in rex.captures_iter(body) {
        let func_params = Router::route(
            "/app/dashboard/:id?",
            |cx| view! {cx, <DashboardCardView/>},
            get(capts.get(1).unwrap().as_str()),
        );
        let itemized = capts;
    }

    view! {cx,
        <>
        <main>
        <article>
        {itemized}
        </article>
        </main>
        </>
    }
}

fn app_dashboard() -> String { return "/app/dashboard".to_owned().to_string(); }

fn nest_dashboard_route() -> Router {
    Router::new().nest_service(
        &app_dashboard(),
        axum::routing::method_routing::get_service(
            tower_http::services::ServeDir::new("./"),
        ),
    )
}

async fn mount_dashboard_view() {
    tracing_subscriber::fmt::init();

    let app_router = Router::new();
    let localhost_address = SocketAddr::from(([127, 0, 0, 1], 3000));

    let all_routes = app_router.fallback_service(nest_dashboard_route());

    tracing::debug!("Listening on: {:?}", localhost_address);
    axum::Server::bind(&localhost_address)
        .serve(all_routes.into_make_service())
        .await
        .unwrap();

    mount_to_body(|ctx| view! { ctx, <DashboardTemplating /> })
}
