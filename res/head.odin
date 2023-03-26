package headers

import raylib "vendor:raylib"

setup :: proc() -> i8 {
    window_screen_width := 1280
    window_screen_height := 1024
    window_application_title := "Inlaid Library: Night 12"
    
    raylib.InitWindow(window_screen_width, window_screen_height, window_application_title)
    defer raylib.CloseWindow()
    
    raylib.SetTargetFPS(10)

    for !raylib.WindowShouldClose() {
        raylib.BeginDrawing()
        defer raylib.EndDrawing()

        raylib.ClearBackground(raylib.BLANK)
    }

    return 0
}