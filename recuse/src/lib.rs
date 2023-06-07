mod client;
mod server;

use crate::server::components::{
    dashboard_card_template::DashboardCardView,
    dashboard_template_user::DashboardTemplating,
    markdown_editor_user::DocumentMarkups,
};

use leptos::*;
use leptos_meta::*;
use leptos_router::*;

#[derive(Debug, Clone, thiserror::Error)]
pub enum AppErrors {
    #[error("Not Found")]
    NotFound,
    #[error("Internal Server Error")]
    InternalServerError,
}

impl AppErrors {
    pub fn status_code(&self) -> reqwest::StatusCode {
        match self {
            AppErrors::NotFound => reqwest::StatusCode::NOT_FOUND,
            AppErrors::InternalServerError => {
                reqwest::StatusCode::INTERNAL_SERVER_ERROR
            }
        }
    }
}

pub fn result_into_error(
    cx: Scope, errors: Option<RwSignal<Errors>>,
) -> leptos::RwSignal<leptos::Errors> {
    let Some(errors) = errors else {
        panic!("Expected errors! No errors found!?");
    };

    errors
}

#[component]
pub fn NavRoute(cx: Scope) -> impl IntoView {
    view! {cx,
        <>
        <head>
        <Stylesheet id="leptos" href="/pkg/index.css" />
        <Meta name="dashboard" content="Novelite Web-novels' Dashboard component" />
        <Router>
        <nav>
        <A href = "about" class=move || "about">"About"</A>
        </nav>
        <main>
        <Routes>
        <Route path="markdowns/:id" view=move |cx| view! {cx, <DocumentMarkups />} />
        <Route path=":markdowns?" view=move |cx| view! {cx, <DashboardTemplating />} />
        </Routes>
        </main>
        </Router>
        </head>
        </>
    }
}

#[component]
pub fn App(cx: Scope) -> impl IntoView {
    view! {cx, <NavRoute />}
}
