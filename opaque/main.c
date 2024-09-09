#include <stdio.h>

#include "circle.h"

int main()
{
  // Allocating circle object on stack
  struct circle* my_circle = alloca(get_circle_size());

  const struct coordinates center = {0.0, 0.0};
  const float              radius = 3.0;

  // We need initialize function here, because circle object is hidden and cannot be directly assigned here
  initialize(my_circle, center, radius);

  printf("circle area %f\n", get_area(my_circle));
  printf("circle circumference %f\n", get_perimeter(my_circle));

  // slope at coordinates
  struct coordinates slope_at = {.x = 0, .y = 3};

  printf("circle slope_at{%f, %f} = %f\n", slope_at.x, slope_at.y, get_slope_at(my_circle, slope_at));

  return 0;
}