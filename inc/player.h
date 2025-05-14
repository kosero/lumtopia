#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

#define G 1500
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 300.0f

typedef enum
{
  IDLE,
  WALKING,
  JUMPING,
  FALLING,
} State;

typedef struct Player
{
  Vector2 position;
  float speed;
  State state;
  bool isGrounded;
} Player;

Player create_player(Vector2 position);

#endif // !PLAYER_H
