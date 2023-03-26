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

fn initialise_odin_tx() !void {
    const exe = builder.addExecutable("main", null);
    // exe.addCSourceFile("main.c", File);
    // exe.linkLibC();
    exe.install();
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
    initialise_odin_tx()();
    try add(1, 1);
}
