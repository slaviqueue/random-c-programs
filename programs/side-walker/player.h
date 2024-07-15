#pragma once

#include <stdbool.h>
#include "side-walker/world.h"

typedef struct {
  int _position_x;
  int _position_y;
  bool _is_falling;
} Player;

Player* player_make();
void player_free(Player** self);
void player_control(Player* self, World* world);
void player_draw(Player* self);