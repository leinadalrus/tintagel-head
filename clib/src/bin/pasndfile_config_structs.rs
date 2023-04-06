struct PaTime(pub f32);

struct PaSampleFormat(pub u64);

struct PaDeviceIndex(pub u8);

struct PaHostApiIndex(pub u8);

pub(crate) struct PaDeviceInfo {
    struct_version: u8, /* this is struct version 2 */
    name: String,
    host_api_index: PaHostApiIndex,
    /**< note this is a host API index, not a type id*/
    max_input_channels: u8,
    max_output_channels: u8,

    /** Default latency values for interactive performance. */
    default_low_input_latency: PaTime,
    default_low_output_latency: PaTime,
    /** Default latency values for robust non-interactive applications (eg. playing sound files). */
    default_high_input_latency: PaTime,
    default_high_output_latency: PaTime,

    default_sample_rate: f32,
}

impl PaDeviceInfo {
    pub fn init() -> PaDeviceInfo {
        PaDeviceInfo {
            name: String::from("Hello World!"),
            host_api_index: PaHostApiIndex(0),
            struct_version: 1,
            max_input_channels: 2,
            max_output_channels: 2,
            default_low_input_latency: PaTime(0.0),
            default_low_output_latency: PaTime(0.0),
            default_high_input_latency: PaTime(0.0),
            default_high_output_latency: PaTime(0.0),
            default_sample_rate: 44100.0,
        }
    }
}

impl Default for PaDeviceInfo {
    fn default() -> Self {
        PaDeviceInfo::init()
    }
}

struct PaStreamParameters {
    /** A valid device index in the range 0 to (Pa_GetDeviceCount()-1)
     specifying the device to be used or the special constant
     paUseHostApiSpecificDeviceSpecification which indicates that the actual
     device(s) to use are specified in hostApiSpecificStreamInfo.
     This field must not be set to paNoDevice.
    */
    device: PaDeviceIndex,

    /** The number of channels of sound to be delivered to the
     stream callback or accessed by Pa_ReadStream() or Pa_WriteStream().
     It can range from 1 to the value of maxInputChannels in the
     PaDeviceInfo record for the device specified by the device parameter.
    */
    channelCount: i8,

    /** The sample format of the buffer provided to the stream callback,
     a_ReadStream() or Pa_WriteStream(). It may be any of the formats described
     by the PaSampleFormat enumeration.
    */
    sampleFormat: PaSampleFormat,

    /** The desired latency in seconds. Where practical, implementations should
     configure their latency based on these parameters, otherwise they may
     choose the closest viable latency instead. Unless the suggested latency
     is greater than the absolute upper limit for the device implementations
     should round the suggestedLatency up to the next practical value - ie to
     provide an equal or higher latency than suggestedLatency wherever possible.
     Actual latency values for an open stream may be retrieved using the
     inputLatency and outputLatency fields of the PaStreamInfo structure
     returned by Pa_GetStreamInfo().
     @see default*Latency in PaDeviceInfo, *Latency in PaStreamInfo
    */
    suggestedLatency: PaTime,

    /** An optional pointer to a host api specific data structure
     containing additional information for device setup and/or stream processing.
     hostApiSpecificStreamInfo is never required for correct operation,
     if not used it should be set to NULL.
    */
    hostApiSpecificStreamInfo: libc::c_void,
}


fn main() {}