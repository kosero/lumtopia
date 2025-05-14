#include <raylib.h>

#include "game.h"

int main(void)
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetConfigFlags(FLAG_VSYNC_HINT);

  InitWindow(SWIDTH, SHEIGHT, "lumtopia");

  while (!WindowShouldClose())
  {
  }

  CloseWindow();
  return 0;
}
