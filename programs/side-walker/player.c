#include "player.h"
#include <curses.h>
#include <stdbool.h>
#include <stdlib.h>
#include "side-walker/colors.h"
#include "side-walker/common.h"
#include "side-walker/point.h"
#include "side-walker/world.h"

static bool can_go_through(Player* player, World* world, Point offset);

Player* player_make() {
  Player* player = malloc(sizeof(Player));

  if (!player)
    crash("could not allocate player");

  player->_is_falling = true;
  player->_position_x = 10;
  player->_position_y = 10;
  return player;
}

void player_free(Player** self) {
  free(*self);
  *self = NULL;
}

void player_control(Player* self, World* world) {
  int key = getch();

  switch (key) {
    case 'a':
      if (can_go_through(self, world, (Point){-1, 0}))
        self->_position_x--;
      break;

    case 'd':
      if (can_go_through(self, world, (Point){+1, 0}))
        self->_position_x++;
      break;

    case ' ':
      if (!self->_is_falling) {
        self->_position_y -= 3;
        self->_is_falling = true;
      }
      break;
  }

  if (can_go_through(self, world, (Point){0, 1}))
    self->_position_y++;
  else
    self->_is_falling = false;
}

void player_draw(Player* self) {
  move(self->_position_y, self->_position_x);
  attron(COLOR_PAIR(ColorPairPlayer));
  printw("F");
  attroff(COLOR_PAIR(ColorPairPlayer));
}

static bool can_go_through(Player* player, World* world, Point offset) {
  return world_is_penetrable(world, (Point){player->_position_x + offset.x,
                                            player->_position_y + offset.y});
}
