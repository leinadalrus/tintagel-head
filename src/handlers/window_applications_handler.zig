const raylib = @cImport({
    @Include("raylib.h");
});

pub fn initialise_window_application() !void {
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
