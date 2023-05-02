use crate::dist::pasndfile_config_structs::PaDeviceInfo;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        unsafe fn handle_query_attache_device(pa_device_info: PaDeviceInfo);
    }
}

fn main() {
    unsafe {
        let pasnd_device = PaDeviceInfo::default();
        handle_query_attache_device(pasnd_device);
    }
}
