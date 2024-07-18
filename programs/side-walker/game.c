#include "side-walker/game.h"
#include <curses.h>
#include <stdlib.h>
#include "side-walker/colors.h"
#include "side-walker/common.h"
#include "side-walker/player.h"
#include "side-walker/point.h"
#include "side-walker/viewport.h"
#include "side-walker/world.h"

static void handle_exit();
static void init_curses();
static WINDOW* make_viewport_window();

static int previous_cursor_mode;

GameState* game_make() {
  GameState* game = malloc(sizeof(GameState));

  if (!game)
    crash("could not allocate game");

  init_curses();
  WINDOW* viewport_window = make_viewport_window();
  game->_viewport = viewport_make(viewport_window);
  game->_player = player_make();
  game->_world = world_make();

  previous_cursor_mode = 0;

  return game;
}

void game_free(GameState** self) {
  viewport_free(&(*self)->_viewport);
  player_free(&(*self)->_player);
  world_free(&(*self)->_world);

  free(*self);
  *self = NULL;
}

void game_init(GameState* self) {
  world_generate(self->_world);
  viewport_set_position(self->_viewport, (Point){self->_player->_position_x,
                                                 self->_player->_position_y});
}

void game_loop(GameState* self) {
  player_control(self->_player, self->_world, self->_viewport->_win);

  Point viewport_position = viewport_get_position(self->_viewport);
  Point new_viewport_position = viewport_position;

  if (self->_player->_position_x - viewport_position.x > 3)
    new_viewport_position.x++;
  if (viewport_position.x - self->_player->_position_x > 3)
    new_viewport_position.x--;

  new_viewport_position.y = self->_player->_position_y;
  viewport_set_position(self->_viewport, new_viewport_position);

  // refresh();
  world_draw(self->_world, self->_viewport);
  player_draw(self->_player, self->_viewport);
}

static void handle_exit() {
  curs_set(previous_cursor_mode);
  endwin();
}

static WINDOW* make_viewport_window() {
  WINDOW* win = newwin(VIEWPORT_HEIGHT, VIEWPORT_WIDTH, 0, 0);
  box(win, '|', '-');
  noecho();
  start_color();
  colors_register();
  wtimeout(win, GETCH_TIMEOUT);

  return win;
}

static void init_curses() {
  initscr();

  if (!has_colors()) {
    fprintf(stderr, "No colors\n");
    exit(EXIT_FAILURE);
  }

  previous_cursor_mode = curs_set(0);
  atexit(handle_exit);
}
