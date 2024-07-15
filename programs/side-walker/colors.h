#pragma once

typedef enum {
  ColorGrassGreenBg = 64,
  ColorGrassGreenFg = 76,
  ColorDirtBg = 172,
  ColorDirtFg = 58,
  ColorTreeBg = 2,
  ColorTreeFg = 47,
  ColorPlayerBg = 9,
  ColorPlayerFg = 1,
} Color;

typedef enum {
  ColorPairGrass = 16,
  ColorPairDirt,
  ColorPairTree,
  ColorPairPlayer
} ColorPair;

void colors_register();
