const std = @import("std");
const assert = std.debug.assert;
const fs = std.fs;
const mem = std.mem;
const zbs = std.build;
const cURL = @cImport({
    @cInclude("curl/curl.h");
});

const File = &[_][]const u8{};
const String = *const []u8;

fn callback(data: *anyopaque, size: c_uint, nmemb: c_uint, user_data: *anyopaque) callconv(.C) c_uint {
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
    if (cURL.curl_easy_setopt(handle, cURL.CURLOPT_WRITEFUNCTION, callback) != cURL.CURLE_OK) {
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
} // compile with `zig build-exe ./src/main.zig --library curl --library c $(pkg-config --cflags libcurl)`

fn build(builder: *zbs.Builder) void {
    const exe = builder.addExecutable("main", null);
    exe.addCSourceFile("main.c", File);
    exe.linkLibC();
    exe.install();
}

pub fn main() void {
    const builder = *zbs.Builder;
    build(builder);
    try curle();
}
