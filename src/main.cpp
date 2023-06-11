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
#define WINDOW_APPLICATION_TITLE "Pfks!AnamNemesis!"
// FPS is defined as so to be base-10:
#define FPS_SET_TARGET 10
// FPS target is 10, but -2 for 8 to reflect spritesheet animation indices
// +2 additional frames for collision and invincibility

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
} PlayerServiceLocator; // TODO: turn into a temporary address array system

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

int initd_checked_player_instance(PlayerServiceLocator *service_instance) {
  struct PlayerEntity {
    PlayerServiceLocator player_service_locator;
  } player_entity = {
      .player_service_locator = service_instance,
  };

  return 0;
}

struct PlayerEntity *designate_entity_scalar(PlayerEntity player_instance) {
  PlayerServiceLocator *player_service_locator;
  // TODO: move player_entity data into a new ServiceLocator function

  PlayerEntity *new_player = &player_instance;
  new_player->player_service_locator = player_service_locator;

  return new_player; // return address of stack memory associated with local
                     // variable
}

int annul_player_entity_instance(PlayerEntity *player_entity) {
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

int check_linked_bundle_instance(PlayerEntity *player_instance) {
  struct PlayerBundle {
    PlayerEntity entity;
    Position position;
    Health health;
    Texture2D sprite;
  } bundle_instance = {
      .entity = *designate_entity_scalar(
          *player_instance), // pointer-to-address because of
                             // address of stack memory
      .position = {350.f, 280.f},
      .health = 100,
      .sprite = LoadTexture(
          "./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  return 0;
}

PlayerBundle *init_player_bundle_instance(PlayerBundle *bundle_instance,
                                          PlayerEntity player_instance) {
  bundle_instance->entity =
      *designate_entity_scalar(player_instance); // pointer-to-address because
                                                 // of address of stack memory
  bundle_instance->position.position.x = 350.f;
  bundle_instance->position.position.y = 280.f;
  bundle_instance->health.health = 100;
  bundle_instance->sprite =
      LoadTexture("./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png");

  PlayerBundle *bundled = bundle_instance;

  return bundled; // may need memcpy and memmove
}

int main() {
  InitWindow(WINDOW_SCREEN_SIZE_WIDTH, WINDOW_SCREEN_SIZE_HEIGHT,
             WINDOW_APPLICATION_TITLE);

  int current_frame = 0;
  int frame_count = 0;
  int frame_speed = 8;

  const int max_frame_speed = 16;
  const int min_frame_speed = 1;

  PlayerServiceLocator *service_instance;

  struct PlayerEntity *player_instance;
  player_instance->player_service_locator = service_instance;

  struct PlayerBundle {
    PlayerEntity entity;
    Position position;
    Health health;
    Texture2D sprite;
  } bundle_instance = {
      .entity = *designate_entity_scalar(
          *player_instance), // pointer-to-address because of
                             // address of stack memory
      .position = {350.f, 280.f},
      .health = 100,
      .sprite = LoadTexture(
          "./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  PlayerBundle *bundled;
  bundled = memset(&bundle_instance, 0, sizeof bundle_instance);

  PlayerBundle *player = init_player_bundle_instance(bundled, *player_instance);

  SetTargetFPS(FPS_SET_TARGET);

  while (!WindowShouldClose()) {
    frame_count++;

    if (frame_count >= (60 / frame_speed)) {
      frame_count = 0;
      current_frame++;
      if (current_frame > 5)
        current_frame = 0;
    }

    if (IsKeyPressed(KEY_D))
      frame_speed++; // do an opposing velocity check
    else if (IsKeyPressed(KEY_A))
      frame_speed--; // and then frame_speed++

    if (frame_speed > max_frame_speed)
      frame_speed = max_frame_speed;
    else if (frame_speed < min_frame_speed)
      frame_speed = min_frame_speed;

    DrawTexture(player->sprite, 255, 255, WHITE);

    EndDrawing();
  }

  for (int i = 0; i < sizeof *bundled; ++i) {
    free(bundled);
    annul_player_entity_instance(player_instance);
    annul_player_service_location(service_instance);
  }

  annul_player_service_location(player->entity.player_service_locator);
  annul_player_entity_instance(&player->entity);
  UnloadTexture(player->sprite);
  // finally close the window instance
  CloseWindow();

  return 0;
}
