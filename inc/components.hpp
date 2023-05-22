#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#elif __linux__
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

const int TILEMAP_TILE_SIZE = 32;
const int PLAYER_HITBOX_SIZE = 2;
const int PLAYER_BOXED_ALPHA = 2;

class Map {
public:
  unsigned int x_tiles;
  unsigned int y_tiles;
  unsigned const char *tile_ids;
  unsigned const char *tile_fog;
};

class Health {
  int points; // health points
};

class Position {
  Vector2 x, y;
};

class PlayerEntity {};

class PlayerName {
  const char *name;
};

class PlayerSprite {
  Rectangle dimensions;
  Texture texture;
};

class PlayerBundle {
  PlayerEntity entity;
  PlayerName name;
  PlayerSprite sprite;
  Health health;
  Position position;
};

class EnemyEntity {};

class EnemyName {
  const char *name;
};

class EnemySprite {
  Rectangle dimensions;
  Texture texture;
};

class EnemyBundle {
  EnemyEntity entity;
  EnemyName name;
  EnemySprite sprite;
  Health health;
  Position position;
};

class FriendlyEntity {};

class FriendlyName {
  const char *name;
};

class FriendlySprite {
  Rectangle dimensions;
  Texture texture;
};

class FriendlyBundle {
  FriendlyEntity entity;
  FriendlyName name;
  FriendlySprite sprite;
  Health health;
  Position position;
};

#endif // !COMPONENTS_HPP
