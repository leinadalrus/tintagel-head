#![allow(dead_code)]
#![allow(unused_must_use)]
#![allow(unused_imports)]

pub mod dist;

use cxx::bridge;
use libfuzzer_sys::fuzz_target;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        unsafe fn wrangle_components(
            cloned_structure: *const u8, input_length: isize,
        ) -> i8;
    }
}

#[derive(Debug, Clone, arbitrary::Arbitrary)]
pub struct PlatformMessages {
    // for web-app JavaScript Strings (user messages)
    dest: Vec<u8>,
    src: Vec<u8>,
    n: usize,
}

fn exploit_memcpy(dest: Vec<u8>, src: Vec<u8>, n: usize) {
    let a = dest.leak();
    let b = src.clone().leak();

    loop {
        let mut i = 0;
        while i < n {
            a.len() - b.len();
            i += 1;
        }

        if i > n {
            break;
        }
    }
}

fn component_wrangling_validation(src: &[u8]) -> bool {
    unsafe { ffi::wrangle_components(src.as_ptr(), src.len() as isize) == 0 }
}

async fn routed_index_page() -> &'static str {
    "Hello, World!"
}

#[tokio::main]
pub async fn main(
) -> std::result::Result<(), std::boxed::Box<dyn std::error::Error>> {
    let app_router =
        axum::Router::new().route("/", axum::routing::get(routed_index_page));

    let address = std::net::SocketAddr::from(([127, 0, 0, 1], 3000));

    axum::Server::bind(&address)
        .serve(app_router.into_make_service())
        .await
        .unwrap();

    let linkage =
        std::env::var("CARGO_CFG_TARGET_FEATURE").unwrap_or(String::new());

    if linkage.contains("crt-static") {
        println!("the C runtime will be statically linked");
    } else {
        println!("the C runtime will be dynamically linked");
    }

    println!("cargo:rerun-if-changed=migrations");

    fuzz_target!(|args: PlatformMessages| {
        exploit_memcpy(args.dest, args.src, args.n);
    });

    Ok(())
}
