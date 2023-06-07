// extern crate raylib;

use leptos::*;
use libc::size_t;
use std::{
    boxed::Box,
    error::Error,
    ffi::{c_int, c_void},
};
use wasm_bindgen::prelude::*;
use web_sys::{WebGl2RenderingContext, WebGlProgram, WebGlShader};

#[cfg(target_family = "wasm")]
extern "C" {
    fn emscripten_sets_main_thread(
        thread_fn: extern "C" fn(), clock_rate: i32, spu_clock: i32,
    );
}

#[link(name = "raylib", kind = "static")]
extern "C" {
    fn initialize_table_data() -> c_int;
    fn deinitialize_table_data() -> c_int;
    fn reset_processing_unit() -> c_int;
    fn stop_processing_unit() -> c_int;

    fn set_microprogram_power_count(power_count: size_t) -> c_int;
    fn set_bias(bias: size_t) -> c_int;
    fn set_degrade_bit_by_ten(enable: c_int) -> c_int;
    fn set_apply_bias(enable: c_int) -> c_int;

    fn read_file_encoded_u8(address_offset: size_t) -> c_int;
    fn read_file_encoded_u16(address_offset: size_t) -> c_int;
    fn read_file_encoded_u32(address_offset: size_t) -> c_int;

    fn write_file_encoded_u8(
        address_offset: size_t, address_sizetype: size_t,
    ) -> c_int;
    fn write_file_encoded_u16(
        address_offset: size_t, address_sizetype: size_t,
    ) -> c_int;
    fn write_file_encoded_u32(
        address_offset: size_t, address_sizetype: size_t,
    ) -> c_int;

    fn fifo_flush_data();
    fn fifo_write_data();

    fn set_count(data: c_int);
    fn set_destination_address(data: c_int);
    fn set_timer_reload(data: c_int);
    fn set_length(data: c_int);

    fn start();
    fn run(data: c_int);
}

#[wasm_bindgen(start)]
fn init_binded_start() -> Result<(), JsValue> {
    let document = web_sys::window().unwrap().document().unwrap();
    let canvas = document.get_element_by_id("canvas").unwrap();
    let canvas: web_sys::HtmlCanvasElement =
        canvas.dyn_into::<web_sys::HtmlCanvasElement>()?;

    let context = canvas
        .get_context("webgl2")?
        .unwrap()
        .dyn_into::<WebGl2RenderingContext>()?;
    Ok(())
} // TODO: interop' webgl2 with raylib's "rlgl.h"

#[component]
pub fn ImmediateApplicationInit(cx: Scope) -> impl IntoView {
    view! {cx,
        <>
        </>
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let delta_ret_val = unsafe { start() };
    println!("InitDrawingMode:$deltaRetVal {:?}", delta_ret_val);

    Ok(())
}
