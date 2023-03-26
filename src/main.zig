const std = @import("std");
const assert = std.debug.assert;
const fs = std.fs;
const mem = std.mem;
const zbs = std.build;
const raylib = @cImport({
    @cInclude("raylib.h");
});
const inlaid = @cImport({
    @cInclude("main.h");
});

const File = &[_][]const u8{};
const String = *const []u8;

fn add(a: i32, b: i32) callconv(.C) i32 {
    return a + b;
}

fn setup() callconv(.C) void {
    inlaid.setup();
}

fn build(builder: *std.build.Builder) void {
    const exe = builder.addExecutable("main", null);
    exe.addCSourceFile("main.c", File);
    exe.linkLibC();
    exe.install();
}

fn main() !void {
    const builder = *std.build.Builder;
    build(builder);
    try setup();
    try add(1, 1);
}
