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
use wasm_bindgen::{closure::Closure, JsCast, JsValue};
use web_sys::{AudioContext, Event, HtmlInputElement, HtmlLabelElement};

#[component]
pub fn DashboardCardView(cx: Scope) -> impl IntoView {
    let card_title = "";
    let image_source = "";
    let author_name = "";
    let card_description = "";

    view! {cx,
        <>
        <div>
            <h1>{card_title}</h1>
            <image src={image_source}/>
            <h6><i>{author_name}</i></h6>
            <span>
                <p>{card_description}</p>
            </span>
        </div>
        </>
    }
}

fn interior_component_horizontal_slider(
    document: &web_sys::Document, template_component: &web_sys::HtmlElement,
    name: &str,
) -> Result<HtmlInputElement, JsValue> {
    let horizontal_slider: HtmlInputElement =
        document.create_element("input")?.unchecked_into();
    template_component.append_child(&horizontal_slider)?;

    Ok(horizontal_slider)
} // turn into a horizontal slider found within a reactive component
