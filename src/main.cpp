#include "C:/raylib/raylib/src/raylib.h"

int main(void)
{
  const int screen_width = 1280;
  const int screen_height = 1024;
  const char *window_title = "Inlaid Library";
  Rectangle max_collisions[sizeof(window_title)] = {0};

  InitWindow(screen_width, screen_height, window_title);

  Rectangle player_hitbox = {1, 1, 2, 2};
  Rectangle collision_walls[sizeof(window_title)] = {10, 10, 8, 4};

  int column_spacing = 0;

  for (int i = 0; i < sizeof(window_title); i++)
  {
    collision_walls[i].width = (float)GetRandomValue(50, 200);
    collision_walls[i].height = (float)GetRandomValue(100, 800);
    collision_walls[i].y = screen_height - 130.0f - collision_walls[i].height;
    collision_walls[i].x = -6000.0f + column_spacing;

    column_spacing += (int)collision_walls[i].width;
  }

  Camera2D primary_camera = {0};
  primary_camera.target = (Vector2){player_hitbox.x + 20.0f, player_hitbox.y + 20.0f};
  primary_camera.offset = (Vector2){screen_width / 2.0f, screen_height / 2.0f};
  primary_camera.rotation = 0.0f;
  primary_camera.zoom = 1.0f;

  SetTargetFPS(10);

  while (!WindowShouldClose())
  {
    // Update
    //----------------------------------------------------------------------------------
    // Player movement
    if (IsKeyDown(KEY_RIGHT))
      player_hitbox.x += 2;
    else if (IsKeyDown(KEY_LEFT))
      player_hitbox.x -= 2;

    // Camera target follows player
    primary_camera.target = (Vector2){player_hitbox.x + 20, player_hitbox.y + 20};

    // Camera rotation controls
    if (IsKeyDown(KEY_A))
      primary_camera.rotation--;
    else if (IsKeyDown(KEY_S))
      primary_camera.rotation++;

    // Limit camera rotation to 80 degrees (-40 to 40)
    if (primary_camera.rotation > 40)
      primary_camera.rotation = 40;
    else if (primary_camera.rotation < -40)
      primary_camera.rotation = -40;

    // Camera zoom controls
    primary_camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

    if (primary_camera.zoom > 3.0f)
      primary_camera.zoom = 3.0f;
    else if (primary_camera.zoom < 0.1f)
      primary_camera.zoom = 0.1f;

    // Camera reset (zoom and rotation)
    if (IsKeyPressed(KEY_R))
    {
      primary_camera.zoom = 1.0f;
      primary_camera.rotation = 0.0f;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode2D(primary_camera);

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

    for (int i = 0; i < sizeof(window_title); i++)
      DrawRectangleRec(max_collisions[i], BLACK);

    DrawRectangleRec(player_hitbox, BLUE);

    DrawLine((int)primary_camera.target.x, -screen_height * 10, (int)primary_camera.target.x, screen_height * 10, GREEN);
    DrawLine(-screen_width * 10, (int)primary_camera.target.y, screen_width * 10, (int)primary_camera.target.y, GREEN);

    EndMode2D();

    DrawRectangle(0, 0, screen_width, 5, RED);
    DrawRectangle(0, 5, 5, screen_height - 10, RED);
    DrawRectangle(screen_width - 5, 5, 5, screen_height - 10, RED);
    DrawRectangle(0, screen_height - 5, screen_width, 5, RED);

    DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 250, 113, BLUE);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context

  return 0;
}