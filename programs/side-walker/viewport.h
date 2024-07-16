#pragma once

#include "side-walker/colors.h"
#include "side-walker/point.h"

typedef struct {
  int _viewport_width;
  int _viewport_height;
  Point _world_position;
} Viewport;

typedef struct {
  Point top_left;
  Point bottom_right;
} ViewportBoundingRect;

Viewport* viewport_make();
void viewport_free(Viewport** self);
void viewport_set_position(Viewport* self, Point world_position);
Point viewport_get_position(Viewport* self);
ViewportBoundingRect viewport_get_bouding_rect(Viewport* self);
void viewport_draw(Viewport* self,
                   Point position,
                   char ch,
                   ColorPair color_pair);
