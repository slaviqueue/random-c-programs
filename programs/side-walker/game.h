#pragma once

#include "side-walker/player.h"
#include "side-walker/world.h"

typedef struct {
  World* _world;
  Player* _player;
} GameState;

GameState* game_make();
void game_free(GameState** self);
void game_init(GameState* self);
void game_loop(GameState* self);
