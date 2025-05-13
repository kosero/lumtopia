#include "player.h"
#include <raylib.h>

Player create_player(Vector2 position)
{
  Player player = {0};
  player.position = position;
  player.speed = 0.0f;
  player.canJump = false;
  return player;
}
