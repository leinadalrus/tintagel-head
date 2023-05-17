pub mod client;
pub mod server;

use leptos::{leptos_dom::ev::SubmitEvent, *};

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        unsafe fn invoke(cmd: &str, args: isize);
    }
}

#[component]
fn HandleAnimationBlock(cx: Scope, data_size: i64) -> impl IntoView {
    let (command, set_command) = create_signal(cx, String::new());
    let (argument, set_argument) = create_signal(cx, usize::MIN);
    let cmd; // TODO
    let args; // TODO

    let update_argument = move |ev| {
        let v = event_target_value(&ev);
        set_argument;
    };

    let command_event = move |ev: SubmitEvent| {
        ev.prevent_default();
        spawn_local(async move {
            if ev.default_prevented() {
                return;
            }

            // Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
            ffi::invoke(cmd, args);
        });
    };

    view! { cx,
        <main class="container">
            <p><b>{ move || command.get() }</b></p>
        </main>
    }
}

fn main() {
    mount_to_body(|ctx| view! { ctx, <HandleAnimationBlock data_size=0 /> })
}
