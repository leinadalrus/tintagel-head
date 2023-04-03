const app = @import("main");
const std = @import("std");

const AudioPhaser = struct {
    left_channel: f32,
    right_channel: f32,
};

const AudioManager = struct {};

const SoundName = struct {};

const SoundEntity = struct {};

const AudioBundle = struct {
    channel_phaser: AudioPhaser,
    soundfile_name: SoundName,
    sound_entity: SoundEntity,
};

fn design_template_callback(template: app.File, user: *anyopaque, data: *anyopaque, size: usize, nmemb: usize) !void {
    user = @intToPtr(std.ArrayList(i32), user);
    data = @intToPtr(std.ArrayList(i32), data);
    size = std.heap.ArenaAllocator.init(std.heap.c_allocator);
    nmemb = @intToPtr([*]u8, @ptrToInt(nmemb));
    template = @intToPtr(data, user);
    return app.File{};
}

fn transpose_design_template(template: app.File, data_size: usize, items_expected: *anyopaque, items_parsed: *anyopaque) !void {
    if (design_template_callback != true) {
        return error.CouldNotSetWriteCallback;
    }

    design_template_callback(template, items_parsed, items_expected, data_size, 0);
}
