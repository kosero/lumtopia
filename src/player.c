#include "player.h"

Player player_init(Vector2 position)
{
  Player player = {0};
  player.position = position;
  player.speed = 0.0f;
  return player;
}
