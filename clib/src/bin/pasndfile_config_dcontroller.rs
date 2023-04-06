use self::ffi::handle_query_attache_device;
use crate::bin::pasndfile_config_structs::PaDeviceInfo;
use cxx::bridge;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        unsafe fn handle_query_attache_device(pa_device_info: PaDeviceInfo);
    }
}

fn main() {
    unsafe {
        let pasnd_device = PaDeviceInfo::default();
        handle_query_attache_device(&mut pasnd_device);
    }
}
