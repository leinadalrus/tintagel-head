const std = @import("std");
const assert = std.debug.assert;
const fs = std.fs;
const mem = std.mem;
const cURL = @cImport({
    @cInclude("curl/curl.h");
});
const pa = @cImport({
    @cInclude("../lib/portaudio/include/portaudio.h");
});
const snd = @cImport({
    @cInclude("../lib/libsndfile/include/sndfile.h");
});

const File = &[_][]const u8{};
const String = *const []u8;

const CPaStreamCallbackTimeInfo = struct {
    inputBufferAdcTime: f32, // The time when the first sample of the input buffer was captured at the ADC input
    currentTime: f32, // The time when the stream callback was invoked
    outputBufferDacTime: f32, // The time when the first sample of the output buffer will output the DAC
}; // skeumorphism of the Stream Callback Time Info data-structure from Port Audio
const CCallbackTimeInfo = CPaStreamCallbackTimeInfo; // the struct name is too long

fn curl_callback_c(data: *anyopaque, size: c_uint, nmemb: c_uint, user_data: *anyopaque) callconv(.C) c_uint {
    var buffer = @intToPtr(*std.ArrayList(u8), @ptrToInt(user_data));
    var typed_data = @intToPtr([*]u8, @ptrToInt(data));
    buffer.appendSlice(typed_data[0 .. nmemb * size]) catch return 0;
    return nmemb * size;
}

fn curle(input_uri_path: *const []u8) !void { // try keyword with `!void` return types work well sugared
    var arena_state = std.heap.ArenaAllocator.init(std.heap.c_allocator);
    defer arena_state.deinit();
    // _ = arena_state; // used when not using `defer`

    const arena_allocator = arena_state.allocator();
    // _ = arena_allocator; // used when not using `defer`
    var response_buffer_message = std.ArrayList(u8).init(arena_allocator);
    defer response_buffer_message.deinit();

    if (cURL.curl_global_init(cURL.CURL_GLOBAL_ALL) != cURL.CURLE_OK) {
        return error.CURLGlobalInitFailed;
    }
    errdefer cURL.curl_global_cleanup();

    const handle = cURL.curl_easy_init() orelse return error.CURLHandleInitFailed;
    errdefer cURL.curl_easy_cleanup(handle);

    // set write function callbacks
    if (cURL.curl_easy_setopt(handle, cURL.CURLOPT_WRITEFUNCTION, curl_callback_c) != cURL.CURLE_OK) {
        return error.CouldNotSetWriteCallback;
    }
    if (cURL.curl_easy_setopt(handle, cURL.CURLOPT_WRITEDATA, &response_buffer_message) != cURL.CURLE_OK) {
        return error.CouldNotSetWriteCallback;
    }
    if (cURL.curl_easy_setopt(handle, cURL.CURLOPT_URL, input_uri_path) != cURL.CURLE_OK) {
        return error.CouldNotSetURL;
    }
    if (cURL.curl_easy_perform(handle) != cURL.CURLE_OK) {
        return error.FailedToPerformRequest;
    }
}

fn pasndfile_callback_c(input_buffer: *anyopaque, output_buffer: *anyopaque, frames_per_buffer: u32, time_info: CCallbackTimeInfo, status_flags: c_uint, audio_data: anyopaque) callconv(.C) c_uint {
    input_buffer = @intToPtr(std.ArrayList(f32), input_buffer);
    output_buffer = @intToPtr(std.ArrayList(f32), output_buffer);
    audio_data = @intToPtr(std.ArrayList(f32), audio_data);
    status_flags = 0;
    time_info = std.heap.ArenaAllocator.init(std.heap.c_allocator);
    frames_per_buffer = @intToPtr([*]u8, @ptrToInt(audio_data));
    return 0;
} // NOTE: give the user inputted parameters heap memory allocated values to make them tangible.

fn pasndfile_backend_setup() !void {
    if (pasndfile_callback_c == 0) {
        return error.CouldNotSetWriteCallback;
    }
}

fn main() !void {
    try curle();
} // compile with `zig build-exe ./src/main.zig --library curl --library c $(pkg-config --cflags libcurl)`
