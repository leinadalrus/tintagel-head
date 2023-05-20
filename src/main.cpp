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

#include "../inc/components.hpp"

int main() {
  InitWindow(600, 400, "High Hunt");
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
