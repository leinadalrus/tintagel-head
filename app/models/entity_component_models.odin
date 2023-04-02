package models 
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