#include "colors.h"
#include <curses.h>

void colors_register() {
  init_pair(ColorPairGrass, ColorGrassGreenFg, ColorGrassGreenBg);
  init_pair(ColorPairDirt, ColorDirtFg, ColorDirtBg);
  init_pair(ColorPairTree, ColorTreeFg, ColorTreeBg);
  init_pair(ColorPairPlayer, ColorPlayerFg, ColorPlayerBg);
}
