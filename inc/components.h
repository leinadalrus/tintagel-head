#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#elif __linux__
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#ifndef COMPONENTS_H
#define COMPONENTS_H

const int TILEMAP_TILE_SIZE = 32;
const int PLAYER_HITBOX_SIZE = 2;
const int PLAYER_BOXED_ALPHA = 2;

typedef struct Map {
  unsigned int x_tiles;
  unsigned int y_tiles;
  unsigned const char *tile_ids;
  unsigned const char *tile_fog;
} Map;

typedef struct Health {
  int points; // health points
} Health;

typedef struct Position {
  Vector2 x, y;
} Position;

typedef struct PlayerEntity {
} PlayerEntity;

typedef struct PlayerName {
} PlayerName;

typedef struct PlayerSprite {
  Rectangle dimensions;
  Texture texture;
} PlayerSprite;

typedef struct PlayerBundle {
  PlayerEntity entity;
  PlayerName name;
  PlayerSprite sprite;
  Health health;
  Position position;
} PlayerBundle;

typedef struct EnemyEntity {
} EnemyEntity;

typedef struct EnemyName {
  const char *name;
} EnemyName;

typedef struct EnemySprite {
  Rectangle dimensions;
  Texture texture;
} EnemySprite;

typedef struct EnemyBundle {
  EnemyEntity entity;
  EnemyName name;
  EnemySprite sprite;
  Health health;
  Position position;
} EnemyBundle;

typedef struct FriendlyEntity {
} FriendlyEntity;

typedef struct FriendlyName {
  const char *name;
} FriendlyName;

typedef struct FriendlySprite {
  Rectangle dimensions;
  Texture texture;
} FriendlySprite;

typedef struct FriendlyBundle {
  FriendlyEntity entity;
  FriendlyName name;
  FriendlySprite sprite;
  Health health;
  Position position;
} FriendlyBundle;

#endif // !COMPONENTS_H
