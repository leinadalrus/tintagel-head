package handlers

import raylib "vendor:raylib"

import "core:fmt"
import "core:math"
import "core:runtime"

import models "../models"

sin_tau :: proc(angle_in_cycles: f64) -> f64 { 	// http://odin-lang.org/docs/overview/#procedures-using-explicit-parametric-polymorphism-parapoly
	angle_in_cycles := angle_in_cycles // Allows `angle_in_cycles` to have its value changed

	TAU :: 2 * math.PI
	angle_in_cycles *= TAU
	return math.sin(angle_in_cycles)
}

handle_player_inputs :: proc() {
	player := models.PlayerBundle{}
	mouse := raylib.GetMousePosition()

	if raylib.IsKeyDown(raylib.KeyboardKey.W) {
		player.position.y += 1.0
	}
	if raylib.IsKeyDown(raylib.KeyboardKey.A) {
		player.position.x -= 1.0
	}
	if raylib.IsKeyDown(raylib.KeyboardKey.S) {
		player.position.y += 1.0
	}
	if raylib.IsKeyDown(raylib.KeyboardKey.D) {
		player.position.x += 1.0
	}
}

// Game Loop
initialise_application_tx :: proc() {
	application_state := models.GameStates.Pause
	detection := models.CollisionDetection.Detected

	models.LateralMovementCounter = .0
	models.LongitudinalMovementCounter = .0
	models.ClientTickrate = .0

	sin_tau(models.ClientTickrate)

	models.ItemizedGridmap = {}

	for i in 0 ..< models.SQUARE_SIZE_AXIS_X {
		for j in 0 ..< models.SQUARE_SIZE_AXIS_Y {
			switch {
			case j == models.SQUARE_SIZE_AXIS_Y - 1, i == models.SQUARE_SIZE_AXIS_X - 1, i == 0:
				models.ItemizedGridmap[i][j] = models.GridmapEntities.Blocking
			}
		}
	}
}

update_application_tx :: proc() {
	if raylib.IsKeyPressed(.ESCAPE) {
		raylib.CloseWindow()
	}

	switch {
	case raylib.IsKeyPressed(
		.LEFT,
	), raylib.IsKeyPressed(.RIGHT), raylib.IsKeyPressed(.A), raylib.IsKeyPressed(.D):
		models.LateralMovementCounter = models.LATERAL_SPEED
		models.LongitudinalMovementCounter = models.LONGITUDINAL_SPEED
		models.ClientTickrate /= models.LateralMovementCounter * models.LongitudinalMovementCounter
	case: // default
	}
}

draw_application_tx :: proc() {
	current_frame := 0
	frame_counter := 0
	framerate := 10

	frame_counter += 1 // note: to-do; force frame increase somehow?

	if frame_counter >= 60 / framerate {
		frame_counter = 0
		current_frame += 1
		if current_frame > 5 {
			current_frame = 0
		}
	}
}

draw_application_rx :: proc() {
	player_sprite := raylib.LoadTexture("assets/sprites/player_front.png")
	player_position := .0
	player_width := f32(player_sprite.width)
	player_height := f32(player_sprite.height) // The cast operator can also be used to do the same thing
	player_hitbox := raylib.Rectangle{0.0, 0.0, player_width, player_height}
	player := models.PlayerBundle{}

	raylib.DrawTexture(player_sprite, 16, 16 * 2, raylib.BLANK)

	for i := 0; i < models.MaxFrameSpeed; i += 1 {
		if i < 10 { /* framerate := 10 */
			raylib.DrawTextureRec(
				player_sprite,
				player_hitbox,
				player.position.delta,
				raylib.BLANK,
			)
		}
	}
}

unload_sprite_system :: proc() {
	player_sprite := raylib.LoadTexture("assets/sprites/player_front.png")
	raylib.UnloadTexture(player_sprite)
}

// setup
setup :: proc() {
	window_screen_width: i32 = 1280
	window_screen_height: i32 = 1024
	window_application_title: cstring = "Inlaid Library: Night 12"

	raylib.InitWindow(window_screen_width, window_screen_height, window_application_title)
	defer raylib.CloseWindow()

	raylib.SetTargetFPS(10)

	for !raylib.WindowShouldClose() { 	// Detect window close button or ESC key
		initialise_application_tx()
		update_application_tx()

		// Raylib Drawing
		raylib.BeginDrawing()

		// Handle Player Inputs
		handle_player_inputs()
		draw_application_tx()
		draw_application_rx()
		defer unload_sprite_system()

		// End Drawing
		defer raylib.EndDrawing()
		raylib.ClearBackground(raylib.BLANK)
	}
}
