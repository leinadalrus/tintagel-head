package controllers
import raylib "vendor:raylib"
import handlers "../handlers"
import models "../models"

OrthographForeground :: struct {}
OrthographBackground :: struct {}
OrthographyBundler :: struct {
	foreground: OrthographForeground,
	background: OrthographBackground,
}

WindowAspect :: struct {
	window_aspect_width:  i32,
	window_aspect_height: i32,
}

set_resolution_by_monitor :: proc() -> WindowAspect {
	window_aspect := WindowAspect{}

	window_aspect.window_aspect_width = raylib.GetScreenWidth()
	window_aspect.window_aspect_height = raylib.GetScreenHeight()

	return window_aspect
}

discriminate_orthographic_layers :: proc() -> OrthographyBundler {
	foreground := OrthographForeground{}
	background := OrthographBackground{}

	return OrthographyBundler{foreground, background}
}

repel_blocked_mapped_items :: proc() {}
