#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

typedef enum
{
  IDLE,
  WALKING,
} Player_state;

typedef struct Player
{
  Vector2 position;
  float speed;
  Player_state state;
} Player;

Player player_init(Vector2 position);

#endif // !PLAYER_H
