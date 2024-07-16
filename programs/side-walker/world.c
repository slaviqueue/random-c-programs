#include "world.h"
#include <curses.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "side-walker/colors.h"
#include "side-walker/common.h"

World* world_make() {
  World* world = malloc(sizeof(World));

  if (!world)
    crash("could not allocate world");

  memset(world->_grid, BlockTypeEmpty,
         WORLD_HEIGHT * WORLD_WIDTH * sizeof(BlockType));
  world->_height = WORLD_HEIGHT;
  world->_width = WORLD_WIDTH;

  return world;
}

void world_free(World** self) {
  free(*self);
  *self = NULL;
}

void world_generate(World* self) {
  for (int x = 0; x < self->_width; x++) {
    int ground_level = 20 - 2 * sin(x / 12.) + sin(x / 2.);
    int dirt_offset = 2 + rand() % 3;

    for (int y = 0; y < self->_height; y++) {
      bool should_draw_a_tree = (y == ground_level - 1) && !(rand() % 10);

      if (should_draw_a_tree) {
        self->_grid[x][y] = BlockTypeTree;
        continue;
      }

      if (y < ground_level)
        continue;

      if (y - ground_level > dirt_offset)
        self->_grid[x][y] = BlockTypeDirt;
      else
        self->_grid[x][y] = BlockTypeGrass;
    }
  }
}

void world_draw(World* self) {
  for (int x = 0; x < self->_width; x++) {
    for (int y = 0; y < self->_height; y++) {
      move(y, x);

      switch (self->_grid[x][y]) {
        case BlockTypeEmpty:
          printw(" ");
          break;
        case BlockTypeGrass:
          attron(COLOR_PAIR(ColorPairGrass));
          printw(".");
          attroff(COLOR_PAIR(ColorPairGrass));
          break;
        case BlockTypeDirt:
          attron(COLOR_PAIR(ColorPairDirt));
          printw(".");
          attroff(COLOR_PAIR(ColorPairDirt));
          break;
        case BlockTypeTree:
          attron(COLOR_PAIR(ColorPairTree));
          printw("F");
          attroff(COLOR_PAIR(ColorPairTree));
          break;
        default:
          break;
      }
    }
  }
  refresh();
}

BlockType world_get_block_type(World* self, Point p) {
  if (p.x < 0 || p.x > self->_width - 1 || p.y < 0 || p.y > self->_height - 1)
    return BlockTypeEmpty;

  return self->_grid[p.x][p.y];
}

bool world_is_penetrable(World* self, Point p) {
  BlockType block_type = world_get_block_type(self, p);
  bool can = block_type == BlockTypeEmpty || block_type == BlockTypeTree;
  return can;
}
