#pragma once

#include <curses.h>

typedef struct {
  WINDOW* _window;
} Dialog;

Dialog* dialog_make(WINDOW* window);
void dialog_free(Dialog** dialog);
