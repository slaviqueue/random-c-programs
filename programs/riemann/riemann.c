#include "riemann/riemann.h"

RiemannStatus riemann_approximate(Integrable fn,
                                  int steps,
                                  Interval interval,
                                  float* result) {
  if (interval.from > interval.to)
    return RiemannStatusFailure;

  float delta_x = (interval.to - interval.from) / steps;
  float approximation = 0;

  for (int i = 0; i < steps; i++) {
    float x_current = interval.from + (i * delta_x);
    float x_next = x_current + delta_x;
    float midpoint = (x_current + x_next) / 2;
    float f_of_x = fn(midpoint);
    float rectangule_area = delta_x * f_of_x;

    approximation += rectangule_area;
  }

  *result = approximation;
  return RiemannStatusSuccess;
}
