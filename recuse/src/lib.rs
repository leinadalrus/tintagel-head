pub mod client;

use leptos::*;

#[component]
fn HandleAnimationBlock(ctx: Scope, data_size: i64) -> impl IntoView {
    let (context_signal, fdatum) = create_signal(ctx, data_size);
    let (viewmodel_signal, vdatum) = create_signal(ctx, data_size);
    let update = move |_| fdatum.update(|context_signal| *context_signal = 0);
    let placeholder = vdatum.update(|context_signal| *context_signal = 0);
    
    view! {ctx,
        <div>
            <button on:click=update>{placeholder}</button>
        </div>

    }
}

fn main() {
    mount_to_body(|ctx| view! { ctx, <HandleAnimationBlock data_size=0 /> })
}