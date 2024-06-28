#define SWAPM(t, a, b) \
  {                    \
    t temp = *a;       \
    *a = *b;           \
    *b = temp;         \
  }
