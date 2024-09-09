#include "circle.h"
#include <assert.h>
#include <math.h>

#define PI 3.143

struct circle
{
  struct coordinates center;
  float              radius;
};

size_t get_circle_size() { return sizeof(struct circle); }

int initialize(struct circle* self, const struct coordinates center, const float radius)
{
  self->center = center;
  self->radius = radius;
}

float get_area(const struct circle* self)
{
  // Calculate the area of the circle
  return PI * self->radius * self->radius;
}

float get_perimeter(const struct circle* self)
{
  // calculate the circumference of the circle
  return 2 * PI * self->radius;
}

float get_slope_at(const struct circle* self, const struct coordinates slope_at)
{
  assert((slope_at.x * slope_at.x) + (slope_at.y * slope_at.y) == (self->radius * self->radius));
  // get the slope of tangent to circle at
  return -slope_at.x / slope_at.y;
}