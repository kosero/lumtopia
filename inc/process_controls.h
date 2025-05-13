#ifndef PROCESS_CONTROLS_H
#define PROCESS_CONTROLS_H

#include "animation.h"
#include "core.h"
#include "player.h"

void update_player(Player* player, Camera2D* camera, Animation* anim,
                   EnvItem* envItems, int envItemsLength, float delta);

#endif // !PROCESS_CONTROLS_H
