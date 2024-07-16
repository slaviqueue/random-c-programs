#pragma once

#include <stdbool.h>
#include "side-walker/point.h"

#define WORLD_WIDTH 100
#define WORLD_HEIGHT 64

typedef enum {
  BlockTypeEmpty,
  BlockTypeGrass,
  BlockTypeDirt,
  BlockTypeTree,
} BlockType;

typedef struct {
  BlockType _grid[WORLD_WIDTH][WORLD_HEIGHT];
  int _width;
  int _height;
} World;

World* world_make();
void world_free(World** self);
void world_generate(World* self);
void world_draw(World* self);
BlockType world_get_block_type(World* self, Point p);
bool world_is_penetrable(World* self, Point p);
