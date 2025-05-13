#ifndef CORE_H
#define CORE_H

#include <raylib.h>

#define SWIDTH 800
#define SHEIGHT 600

typedef struct EnvItem
{
  Rectangle rect;
  int blocking;
  Color color;
} EnvItem;

#endif // !CORE_H
