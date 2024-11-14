#include "riemann/riemann.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <math.h>
#include <stdio.h>

float some_weird_function(float x) {
  return -pow(x, 2) - x;
}

Test(riemann_calculate, calculates_riemann_sum) {
  Interval interval = {-1, 2};
  int steps = 5;
  float actual_approximation;
  RiemannStatus status = riemann_approximate(some_weird_function, steps,
                                             interval, &actual_approximation);
  float expected_approximation = -441.0 / 100.0;

  printf("%f\n", actual_approximation);
  cr_expect_eq(status, RiemannStatusSuccess);
  cr_expect_float_eq(actual_approximation, expected_approximation, 0.0001);
}
