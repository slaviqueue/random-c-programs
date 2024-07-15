#pragma once

#include <stdbool.h>
#include "side-walker/point.h"

#define WORLD_WIDTH 64
#define WORLD_HEIGHT 64

typedef enum {
  BlockTypeEmpty,
  BlockTypeGrass,
  BlockTypeDirt,
  BlockTypeTree,
} BlockType;

typedef struct {
  BlockType _grid[WORLD_HEIGHT][WORLD_WIDTH];
  int _width;
  int _height;
} World;

World* world_make();
void world_free(World** self);
void world_generate(World* self);
void world_draw(World* self);
BlockType world_get_block_type(World* self, Point p);
bool is_penetrable(World* self, Point p);
