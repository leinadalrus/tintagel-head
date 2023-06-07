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

struct ContentCreation {
    id: uuid::Uuid,
}

struct DocumentAuthor {
    id: uuid::Uuid,
    username: String,
}

impl DocumentAuthor {
    pub fn new() -> Self {
        DocumentAuthor {
            id: uuid::Uuid::new_v4(),
            username: String::new(),
        }
    }
}

struct MarkdownDocument {
    path: ContentCreation,
    author: DocumentAuthor,
}

impl Default for MarkdownDocument {
    fn default() -> Self {
        let created_content = ContentCreation {
            id: uuid::Uuid::new_v4(),
        };
        let author_init = DocumentAuthor::new();
        MarkdownDocument {
            path: created_content,
            author: author_init,
        }
    }
}

#[component]
pub fn DocumentMarkups(cx: Scope) -> impl IntoView {
    // axum parameter routing
    // C.R.U.D document data-model
    tracing_subscriber::fmt::init();

    let file_path = env::current_dir();
    let body = fs::read_to_string(file_path).expect("Expected File Contents!?");

    let rex = Regex::new(r"/[^\\]*\.(md)$/");
    let mut conts; // free value for replacing `capts` value

    for capts in rex.captures_iter(body) {
        let func_params =
            Router::route("./content/{}", get(capts.get(1).unwrap().as_str()));
        let conts = capts;
    }

    view! {cx,
        <>
        <template>
        <main class="editor-editing-space">
        <article>
        {conts}
        </article>
        </main>
        </template>
        </>
    }
}

pub struct MarkdownBundle {
    markdown: MarkdownDocument,
}

impl MarkdownBundle {
    pub fn handle() -> Result<(), std::boxed::Box<dyn std::error::Error>> {
        Ok(())
    }
}

async fn mount_markdown_template() -> (StatusCode, Json<MarkdownDocument>) {
    mount_to_body(|ctx| view! { ctx, <DocumentMarkups /> });
    let markdown: &MarkdownDocument; // TODO
    (StatusCode::CREATED, Json(markdown))
}
