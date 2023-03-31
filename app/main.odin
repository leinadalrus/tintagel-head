package controllers

import raylib "vendor:raylib"

import "core:fmt"
import "core:math"
import "core:runtime"

// Constants
SQUARE_SIZE_CAPACITY :: 32
SQUARE_SIZE_AXIS_X :: 16
SQUARE_SIZE_AXIS_Y :: 16

LATERAL_SPEED :: 10
LONGITUDINAL_SPEED :: 10

// Global
ItemizedGridmap: [SQUARE_SIZE_AXIS_X][SQUARE_SIZE_AXIS_Y]GridmapEntities
EntityTilemap: [1][1]GridmapEntities

LateralMovementCounter := .0
LongitudinalMovementCounter := .0
ClientTickrate := .0

MaxFrameSpeed :: 10
MinFrameSpeed :: 1

// Enums
GridmapEntities :: enum u8 {
    Empty,
    Blocking,
}

GameStates :: enum i8 {
    GameOver,
    Pause,
}

CollisionDetection :: enum i8 {
    Detected,
}

PlayerEntity :: struct {}

// http://odin-lang.org/docs/overview/#data-types-using-explicit-parametric-polymorphism-parapoly
PlayerName :: struct(name: string) {}

EntityHealth :: struct {
    player_health_points: u8,
}

EntityPosition :: struct {
    x: f32,
    y: f32,
    delta: f32, // delta for encompassing both x and y
}

PlayerSprite :: struct {
    player_sprite_id: string,
}

PlayerBundle :: struct #packed {
    // removed padding between the fields
    entity:   PlayerEntity,
    name:     PlayerName("PlayerEntity"),
    position: EntityPosition,
    health:   EntityHealth,
    sprite:   PlayerSprite,
}

EnemyEntity :: struct {}

EnemyName :: struct(name: string) {}

EnemySprite :: struct {
    player_sprite_id: string,
}

EnemyBundle :: struct #packed {
    // removed padding between the fields
    entity:   EnemyEntity,
    name:     EnemyName("EnemyEntity"),
    position: EntityPosition,
    health:   EntityHealth,
    sprite:   EnemySprite,
}

FriendlyEntity :: struct {}

FriendlyName :: struct(name: string) {}

FriendlySprite :: struct {
    player_sprite_id: string,
}

FriendlyBundle :: struct #packed {
    // removed padding between the fields
    entity:   FriendlyEntity,
    name:     FriendlyName("FriendlyEntity"),
    position: EntityPosition,
    health:   EntityHealth,
    sprite:   FriendlySprite,
}

sin_tau :: proc(angle_in_cycles: f64) -> f64 {  // http://odin-lang.org/docs/overview/#procedures-using-explicit-parametric-polymorphism-parapoly
    angle_in_cycles := angle_in_cycles // Allows `angle_in_cycles` to have its value changed

    TAU :: 2 * math.PI
    angle_in_cycles *= TAU
    return math.sin(angle_in_cycles)
}

handle_player_inputs :: proc() {
    player := PlayerBundle{}
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
    application_state := GameStates.Pause
    detection := CollisionDetection.Detected

    LateralMovementCounter = .0
    LongitudinalMovementCounter = .0
    ClientTickrate = .0

    sin_tau(ClientTickrate)

    ItemizedGridmap = {}

    for i in 0 ..< SQUARE_SIZE_AXIS_X {
        for j in 0 ..< SQUARE_SIZE_AXIS_Y {
            switch {
            case j == SQUARE_SIZE_AXIS_Y - 1, i == SQUARE_SIZE_AXIS_X - 1, i == 0:
                ItemizedGridmap[i][j] = .Blocking
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
        LateralMovementCounter = LATERAL_SPEED
        LongitudinalMovementCounter = LONGITUDINAL_SPEED
        ClientTickrate /= LateralMovementCounter * LongitudinalMovementCounter
    case: // default
    }
}

draw_application_tx :: proc() {
    current_frame := 0
    frame_counter := 0
    framerate := 10
    
    frame_counter += 1 // note: to-do; force frame increase somehow?

    if frame_counter >= 60/framerate {
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
    player := PlayerBundle{}

    raylib.DrawTexture(player_sprite, 16, 16*2, raylib.BLANK)

    for i := 0; i < MaxFrameSpeed; i += 1 {
        if i < 10 { /* framerate := 10 */
            raylib.DrawTextureRec(player_sprite, player_hitbox, player.position.delta, raylib.BLANK)
        }
    }
}

unload_sprite_system :: proc() {
    player_sprite := raylib.LoadTexture("assets/sprites/player_front.png")
    raylib.UnloadTexture(player_sprite)
}

// setup
setup :: proc() {
    window_screen_width : i32 = 1280
    window_screen_height : i32 = 1024
    window_application_title : cstring = "Inlaid Library: Night 12"
    
    raylib.InitWindow(window_screen_width, window_screen_height, window_application_title)
    defer raylib.CloseWindow()
    
    raylib.SetTargetFPS(10)

    for !raylib.WindowShouldClose() { // Detect window close button or ESC key
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

main :: proc() {
    setup()
}