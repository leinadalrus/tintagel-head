#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <io.h> // equivalent to <unistd.h>
#elif __linux__
#include <raylib.h>
#include <unistd.h> // equivalent to <io.h>
#endif

#if _WIN32 || __linux__
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#define WINDOW_SCREEN_SIZE_WIDTH 600
#define WINDOW_SCREEN_SIZE_HEIGHT 480
#define WINDOW_APPLICATION_TITLE "Anamnemesis!"
#define FPS_SET_TARGET 60

typedef struct Collision {
  Rectangle hitbox;
} Collision;

typedef struct Position {
  Vector2 position;
} Position;

typedef struct Health {
  uint8_t health;
} Health;

typedef struct PlayerServiceLocator {
  void *destination, *source, *data;
  uint16_t size;
} PlayerServiceLocator;

typedef struct PlayerServiceAvails {
  PlayerServiceLocator *live_services;
} PlayerServiceAvails;

typedef struct AnnulPlayerService {
  PlayerServiceLocator *player_service_locator;
} AnnulPlayerService;

int annul_player_service_location(
    PlayerServiceLocator *player_service_locator) {
  free(player_service_locator);
  player_service_locator = NULL;
  return 0;
}

typedef struct PlayerEntity {
  PlayerServiceLocator *player_service_locator;
} PlayerEntity;

struct PlayerEntity *designate_entity_scalar() {
  PlayerServiceLocator *player_service_locator;
  // TODO: move player_entity data into a new ServiceLocator function
  struct PlayerEntity {
    PlayerServiceLocator player_service_locator;
  } player_entity = {
      .player_service_locator = player_service_locator,
  };

  return &player_entity; // return address of stack memory associated with local
                         // variable
}

int annul_player_entity_inst(PlayerEntity *player_entity) {
  free(player_entity);
  player_entity = NULL;
  return 0;
}

typedef struct PlayerName {
  const char *name;
} PlayerName;

typedef struct PlayerBundle {
  PlayerEntity entity;
  Position position;
  Health health;
  Texture2D sprite;
} PlayerBundle;

PlayerBundle *init_player_bundle_instance() {
  struct PlayerBundle {
    PlayerEntity entity;
    Position position;
    Health health;
    Texture2D sprite;
  } player = {
      .entity = *designate_entity_scalar(), // pointer-to-address because of
                                            // addres of stack memory
      .position = {350.f, 280.f},
      .health = 100,
      .sprite = LoadTexture(
          "./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  return &player; // may need memcpy and memmove
}

int main() {
  InitWindow(WINDOW_SCREEN_SIZE_WIDTH, WINDOW_SCREEN_SIZE_HEIGHT,
             WINDOW_APPLICATION_TITLE);

  PlayerBundle *player = init_player_bundle_instance();

  SetTargetFPS(FPS_SET_TARGET);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLANK);

    EndDrawing();
  }

  annul_player_service_location(player->entity.player_service_locator);
  annul_player_entity_inst(&player->entity);

  CloseWindow();

  return 0;
}
