const std = @import("std");
const assert = std.debug.assert;
const fs = std.fs;
const mem = std.mem;
const zbs = std.build;

fn add(a: i32, b: i32) callconv(.C) i32 {
    return a + b;
}

fn build(builder: *std.build.Builder) void {
    const exe = b.addExecutable("main", null);
    exe.addCSourceFile("main.c", &[_][]const u8{});
    exe.linkLibC();
    exe.install();
}

pub fn main() !void {
    add(1, 1);
}
