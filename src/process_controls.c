#include <raylib.h>

#include "process_controls.h"

void update_player(Player* player, Camera2D* camera, Animation* anim,
                   EnvItem* envItems, int envItemsLength, float delta)
{
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
  {
    player->position.x -= PLAYER_HOR_SPD * delta;
    anim->flipped = false;
  }
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
  {
    player->position.x += PLAYER_HOR_SPD * delta;
    anim->flipped = true;
  }
  if ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) &&
      player->canJump)

  {
    player->speed = -PLAYER_JUMP_SPD;
    player->canJump = false;
  }

  bool hitObstacle = false;
  for (int i = 0; i < envItemsLength; i++)
  {
    EnvItem* ei = envItems + i;
    Vector2* p = &(player->position);
    if (ei->blocking && ei->rect.x <= p->x &&
        ei->rect.x + ei->rect.width >= p->x && ei->rect.y >= p->y &&
        ei->rect.y <= p->y + player->speed * delta)
    {
      hitObstacle = true;
      player->speed = 0.0f;
      p->y = ei->rect.y;
      break;
    }
  }

  if (!hitObstacle)
  {
    player->position.y += player->speed * delta;
    player->speed += G * delta;
    player->canJump = false;
  }
  else
    player->canJump = true;

  int width = GetScreenWidth();
  int height = GetScreenHeight();

  camera->offset = (Vector2){width / 2.0f, height / 2.0f};
  camera->target = player->position;
}
