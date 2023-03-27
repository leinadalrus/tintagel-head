#![allow(unused_must_use)]
use libfuzzer_sys::fuzz_target;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        
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