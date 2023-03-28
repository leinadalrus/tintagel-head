#![allow(unused_must_use)]
#![allow(unused_imports)]
use libfuzzer_sys::fuzz_target;
use cxx::UniquePtr;

#[cxx::bridge(namespace = "com::app")]
mod ffi {
    unsafe extern "C++" {
        include!("./include/components.h");
        type PlayerEntity;
        fn init_shared_player_entity() -> UniquePtr<PlayerEntity>;
    }
}

#[derive(Debug, Clone, arbitrary::Arbitrary)]
pub struct CommandlineArgument {
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

        if i > n { break; }
    }
}

fn main() -> std::result::Result<(), std::boxed::Box<dyn std::error::Error>> {
    fuzz_target!(|args: CommandlineArgument| {
        exploit_memcpy(args.dest, args.src, args.n);
    });
    Ok(())
}