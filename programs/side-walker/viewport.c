#include "viewport.h"
#include <curses.h>
#include <stdlib.h>
#include "side-walker/defs.h"
#include "side-walker/point.h"

Viewport* viewport_make() {
  Viewport* viewport = malloc(sizeof(Viewport));
  viewport->_world_position = (Point){0, 0};
  viewport->_viewport_width = VIEWPORT_WIDTH;
  viewport->_viewport_height = VIEWPORT_HEIGHT;
  return viewport;
}

void viewport_free(Viewport** self) {
  free(*self);
  *self = NULL;
}

void viewport_set_position(Viewport* self, Point position) {
  self->_world_position = position;
}

Point viewport_get_position(Viewport* self) {
  return self->_world_position;
}

ViewportBoundingRect viewport_get_bouding_rect(Viewport* self) {
  int half_viewport_width = self->_viewport_width / 2;
  int half_viewport_height = self->_viewport_height / 2;
  int pos_x = self->_world_position.x;
  int pos_y = self->_world_position.y;

  Point top_left = {.x = pos_x - half_viewport_width,
                    .y = pos_y - half_viewport_height};
  Point bottom_right = {.x = pos_x + half_viewport_width,
                        .y = pos_y + half_viewport_height};

  return (ViewportBoundingRect){top_left, bottom_right};
}

void viewport_draw(Viewport* self,
                   Point position,
                   char ch,
                   ColorPair color_pair) {
  if (position.x < 0 || position.x > self->_viewport_width || position.y < 0 ||
      position.y > self->_viewport_height)
    return;

  move(position.y, position.x);
  attron(COLOR_PAIR(color_pair));
  printw("%c", ch);
  attron(COLOR_PAIR(color_pair));
}
