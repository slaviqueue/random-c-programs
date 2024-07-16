#include "side-walker/game.h"
#include <curses.h>
#include <stdlib.h>
#include "side-walker/colors.h"
#include "side-walker/common.h"
#include "side-walker/player.h"
#include "side-walker/world.h"

static void handle_exit();
static void init_curses();

static int previous_cursor_mode;

GameState* game_make() {
  GameState* game = malloc(sizeof(GameState));

  if (!game)
    crash("could not allocate game");

  game->_player = player_make();
  game->_world = world_make();
  previous_cursor_mode = 0;

  return game;
}

void game_free(GameState** self) {
  player_free(&(*self)->_player);
  world_free(&(*self)->_world);
  free(*self);
  *self = NULL;
}

void game_init(GameState* self) {
  init_curses();
  colors_register();
  world_generate(self->_world);
}

void game_loop(GameState* self) {
  refresh();
  player_control(self->_player, self->_world);
  world_draw(self->_world);
  player_draw(self->_player);
}

static void init_curses() {
  initscr();
  noecho();
  start_color();
  timeout(100);

  if (!has_colors()) {
    fprintf(stderr, "No colors\n");
    exit(EXIT_FAILURE);
  }

  previous_cursor_mode = curs_set(0);
  atexit(handle_exit);
}

static void handle_exit() {
  curs_set(previous_cursor_mode);
  endwin();
}
