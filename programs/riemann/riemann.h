#pragma once

typedef struct {
  float from;
  float to;
} Interval;

typedef enum { RiemannStatusSuccess, RiemannStatusFailure } RiemannStatus;

typedef float (*Integrable)(float);

/* This funciton accepts a function of single floating point variable f, whose
 * result is also a float, and approximates the integral of f using the midpoint
 * Riemann sum.
 *
 * If interval.from is greater than interval.to - returns an error status.
 * */
RiemannStatus riemann_approximate(Integrable fn,
                                  int steps,
                                  Interval interval,
                                  float* result);
