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

int main() {
  GameState* game = game_make();
  game_init(game);

  while (true)
    game_loop(game);
}

static void print_palette() {
  const int palette_width = 20;
  const int cell_width = 3;

  for (int i = 0; i < 500; i++) {
    init_pair(i, 0, i);
    attron(COLOR_PAIR(i));
    mvprintw(i / palette_width, cell_width * (i % palette_width), "%*i",
             cell_width, i);
    attroff(COLOR_PAIR(i));
  }

  refresh();

  while (true)
    getch();
}
