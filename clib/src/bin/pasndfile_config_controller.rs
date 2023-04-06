use crate::bin::pasndfile_config_structs::PaDeviceInfo;

#[link(name = "pasnd")]
extern "C" {
    fn handle_query_attache_device(pa_device_info: PaDeviceInfo);
}

fn main() {
    unsafe {
        let pasnd_device = PaDeviceInfo::default();
        handle_query_attache_device(pasnd_device);
    }
}
