#include <raylib.h>
#include <stdio.h>

#include "player.h"

Player player_init(Vector2 position, Vector2 hitbox)
{
  Player player = {0};
  player.position = position;
  player.speed = 0.0f;
  player.hitbox = hitbox;
  return player;
}

void update_player(Player* player, Camera2D* camera, Animation* anim,
                   float delta)
{
  bool moving = false;

  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
  {
    player->position.x -= PLAYER_HOR_SPD * delta;
    anim->flipped = false;
    moving = true;
    player->state = LEFT_WALK;
  }
  else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
  {
    player->position.x += PLAYER_HOR_SPD * delta;
    anim->flipped = true;
    moving = true;
    player->state = RIGHT_WALK;
  }
  else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
  {
    player->position.y -= PLAYER_HOR_SPD * delta;
    anim->flipped = true;
    moving = true;
    player->state = UP_WALK;
  }
  else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
  {
    player->position.y += PLAYER_HOR_SPD * delta;
    anim->flipped = true;
    moving = true;
    player->state = DOWN_WALK;
  }

  if (!moving)
  {
    switch (player->state)
    {
    case LEFT_WALK:
      player->state = LEFT_IDLE;
      break;
    case RIGHT_WALK:
      player->state = RIGHT_IDLE;
      break;
    case UP_WALK:
      player->state = UP_IDLE;
      break;
    case DOWN_WALK:
      player->state = DOWN_IDLE;
      break;
    default:
      break;
    }
  }

  int width = GetScreenWidth();
  int height = GetScreenHeight();
  camera->offset = (Vector2){width / 2.0f, height / 2.0f};
  camera->target = player->position;

  printf("[info]: player x=%.2f, y=%.2f | state=%d\n", player->position.x,
         player->position.y, player->state);
}
