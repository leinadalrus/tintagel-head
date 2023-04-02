package controllers
import raylib "vendor:raylib"
import handlers "../handlers"
import models "../models"

OrthographForeground :: struct {}
OrthographBackground :: struct {}

WindowAspect :: struct {
	window_aspect_width:  i32,
	window_aspect_height: i32,
}

control_window_aspect_dimensions :: proc() -> WindowAspect {
	window_aspect := WindowAspect{}

	window_aspect.window_aspect_width = models.WINDOW_SCREEN_WIDTH
	window_aspect.window_aspect_height = models.WINDOW_SCREEN_HEIGHT

	return window_aspect
}

set_resolution_by_monitor :: proc() -> WindowAspect {
    window_aspect := WindowAspect{}

    window_aspect.window_aspect_width = raylib.GetScreenWidth()
	window_aspect.window_aspect_height = raylib.GetScreenHeight()

    return window_aspect
}

repel_blocked_mapped_items :: proc() {

}
