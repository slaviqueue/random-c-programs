#include "dialog.h"
#include <stdlib.h>

Dialog* dialog_make(WINDOW* window) {
  Dialog* dialog = malloc(sizeof(Dialog));
  dialog->_window = window;
  return dialog;
}

void dialog_free(Dialog** dialog) {
  free(*dialog);
  *dialog = NULL;
}
