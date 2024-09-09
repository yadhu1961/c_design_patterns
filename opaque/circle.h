#include <stdlib.h>
#include "coordinates.h"

// Forward declaration is enough because only pointers are referred in header file
struct circle;

size_t get_circle_size();

int initialize(struct circle* self, const struct coordinates center, const float radius);

float get_area(const struct circle* self);
float get_perimeter(const struct circle* self);
float get_slope_at(const struct circle* self, const struct coordinates slope_at);
