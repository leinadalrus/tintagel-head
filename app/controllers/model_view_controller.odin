package controllers
import handlers "../handlers"
import models "../models"

WindowAspect :: struct {
	window_aspect_width:  int,
	window_aspect_height: int,
}

control_window_aspect_dimensions :: proc() -> WindowAspect {
	window_aspect := WindowAspect{}

	window_aspect.window_aspect_width = models.WINDOW_SCREEN_WIDTH
	window_aspect.window_aspect_height = models.WINDOW_SCREEN_HEIGHT

	return window_aspect
}
