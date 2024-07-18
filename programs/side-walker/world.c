#include "world.h"
#include <curses.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "side-walker/colors.h"
#include "side-walker/common.h"
#include "side-walker/defs.h"
#include "side-walker/viewport.h"

World* world_make() {
  World* world = malloc(sizeof(World));

  if (!world)
    crash("could not allocate world");

  memset(world->_grid, BlockTypeEmpty, sizeof(world->_grid));
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

void world_draw(World* self, Viewport* viewport) {
  ViewportBoundingRect viewport_brect = viewport_get_bouding_rect(viewport);

  for (int x = 0; x < viewport->_viewport_width; x++) {
    for (int y = 0; y < viewport->_viewport_height; y++) {
      int world_x = viewport_brect.top_left.x + x;
      int world_y = viewport_brect.top_left.y + y;

      if (world_x < 0 || world_y < 0) {
        viewport_draw(viewport, (Point){x, y}, ' ', ColorPairSky);
        continue;
      }

      BlockType world_block = self->_grid[world_x][world_y];
      Point point = {x, y};

      switch (world_block) {
        case BlockTypeEmpty:
          viewport_draw(viewport, point, ' ', ColorPairSky);
          break;
        case BlockTypeGrass:
          viewport_draw(viewport, point, '.', ColorPairGrass);
          break;
        case BlockTypeDirt:
          viewport_draw(viewport, point, '.', ColorPairDirt);
          break;
        case BlockTypeTree:
          viewport_draw(viewport, point, 'F', ColorPairTree);
          break;
        default:
          break;
      }
    }
  }
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
