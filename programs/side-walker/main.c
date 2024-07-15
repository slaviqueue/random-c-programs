#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "side-walker/colors.h"
#include "side-walker/game.h"
#include "side-walker/player.h"
#include "side-walker/world.h"

// I don't know where to get all available colors in ncurses, so sometimes I
// just print the whole palette to find a color I need
static void print_palette();
static void handle_exit();
static void init_curses();

int previous_cursor_mode;

int main() {
  // init_curses();
  // colors_register();
  //
  // World* world = world_make();
  // Player* player = player_make();
  //
  // world_generate(world);
  //
  // // print_palette();
  // while (true) {
  //   player_control(player, world);
  //   world_draw(world);
  //   player_draw(player);
  // }
  GameState* game = game_make();
  game_init(game);
  init_curses();
  colors_register();
  world_generate(game->_world);

  while (true)
    game_loop(game);
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
static void print_palette() {
  const int palette_width = 20;
  const int cell_width = 3;
  refresh();

  for (int i = 0; i < 500; i++) {
    init_pair(i, 0, i);
    attron(COLOR_PAIR(i));
    mvprintw(i / palette_width, cell_width * (i % palette_width), "%*i",
             cell_width, i);
    attroff(COLOR_PAIR(i));
  }

  while (true)
    getch();
}
static void handle_exit() {
  curs_set(previous_cursor_mode);
  endwin();
}
