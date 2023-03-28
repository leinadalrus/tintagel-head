#![allow(dead_code)]
#![allow(unused_must_use)]
#![allow(unused_imports)]
use libfuzzer_sys::fuzz_target;
use libc::{c_int, size_t};

#[link(name = "wrangler")]
extern {
    fn wrangle_components(cloned_structure: *const u8,
        input_length: size_t) -> c_int;
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

fn component_wrangling_validation(src: &[u8]) -> bool {
    unsafe {
        wrangle_components(src.as_ptr(), src.len() as size_t) == 0
    }
}

fn main() -> std::result::Result<(), std::boxed::Box<dyn std::error::Error>> {
    fuzz_target!(|args: CommandlineArgument| {
        exploit_memcpy(args.dest, args.src, args.n);
    });
    Ok(())
}