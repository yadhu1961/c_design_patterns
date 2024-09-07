#include "coordinates.h"

struct circle
{
  struct coordinates center;
  float              radius;
};

float get_area(const struct circle* self);
float get_perimeter(const struct circle* self);
float get_slope_at(const struct circle* self, const struct coordinates slope_at);