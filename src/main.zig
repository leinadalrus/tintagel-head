const std = @import("std");
const assert = std.debug.assert;
const fs = std.fs;
const mem = std.mem;
const zbs = std.build;
const raylib = @cImport({
    @cInclude("raylib.h");
});

const File = &[_][]const u8{};
const String = *const []u8;

fn initialise_window_application() !void {
    const window_screen_width = 1280;
    const window_screen_height = 1024;
    const window_application_title = "Night 12";

    raylib.InitWindow(window_screen_width, window_screen_height, window_application_title);
    defer raylib.CloseWindow();

    raylib.SetTargetFPS(10);

    while (!raylib.WindowShouldClose()) {
        raylib.BeginDrawing();
        defer raylib.EndDrawing();

        raylib.ClearBackground(raylib.BLANK);
    }
}

fn add(a: i32, b: i32) callconv(.C) i32 {
    return a + b;
}

fn build(builder: *std.build.Builder) void {
    const exe = builder.addExecutable("main", null);
    exe.addCSourceFile("main.c", File);
    exe.linkLibC();
    exe.install();
}

fn main() !void {
    initialise_window_application();
    try add(1, 1);
}
