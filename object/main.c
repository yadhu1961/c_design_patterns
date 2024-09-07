#include <stdio.h>

#include "circle.h"

int main()
{
  struct circle my_circle = {{.x = 0, .y = 0}, 3.0};

  printf("circle area %f\n", get_area(&my_circle));
  printf("circle circumference %f\n", get_perimeter(&my_circle));

  // slope at coordinates
  struct coordinates slope_at = {.x = 0, .y = 3};

  printf("circle slope_at{%f, %f} = %f\n", slope_at.x, slope_at.y, get_slope_at(&my_circle, slope_at));

  return 0;
}