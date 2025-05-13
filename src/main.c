#include <raylib.h>

#include "animation.h"
#include "core.h"
#include "player.h"
#include "process_controls.h"

int main(void)
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetConfigFlags(FLAG_VSYNC_HINT);
  InitWindow(SWIDTH, SHEIGHT, "lumtopia");

  Player player = create_player((Vector2){400, 280});
  Texture2D player_idle_texture = LoadTexture("./assets/idle.png");
  Animation anim;
  animation_init(&anim, 0, 5, 0.1f, 16, 16, false);

  Camera2D camera = {0};
  camera.target = player.position;
  camera.offset = (Vector2){SWIDTH / 2.0f, SHEIGHT / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  EnvItem envItems[] = {{{0, 380, 1000, 20}, 1, LIME},
                        {{0, 400, 1000, 200}, 1, BROWN},
                        {{300, 200, 400, 10}, 1, WHITE},
                        {{250, 300, 100, 10}, 1, WHITE},
                        {{650, 300, 100, 10}, 1, WHITE}};

  int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

  while (!WindowShouldClose())
  {
    float deltaTime = GetFrameTime();
    animation_update(&anim);

    update_player(&player, &camera, &anim, envItems, envItemsLength, deltaTime);

    camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

    if (camera.zoom > 3.0f)
      camera.zoom = 3.0f;
    else if (camera.zoom < 0.25f)
      camera.zoom = 0.25f;

    if (IsKeyPressed(KEY_R))
    {
      camera.zoom = 1.0f;
      player.position = (Vector2){400, 280};
    }

    BeginDrawing();

    ClearBackground(SKYBLUE);

    BeginMode2D(camera);

    for (int i = 0; i < envItemsLength; i++)
      DrawRectangleRec(envItems[i].rect, envItems[i].color);

    Vector2 pos = {player.position.x - (anim.frame_width * 6) / 2.0f,
                   player.position.y - (anim.frame_height * 6)};

    draw_animation(&anim, player_idle_texture, pos, 6, 5);

    EndMode2D();
    EndDrawing();
  }
  CloseWindow();
}
