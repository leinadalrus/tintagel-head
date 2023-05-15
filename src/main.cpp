#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <raylib.h>

class Health {
  int hp; // health points
};

class Position {
  Vector2 x, y;
};

class PlayerEntity {};

class PlayerName {};

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

int main() {
  InitWindow(600, 400, "Inlaid Imperial");
  Camera2D camera = {0};

  while (!WindowShouldClose()) {
    BeginDrawing();
    BeginMode2D(camera);
    ClearBackground(BLANK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
