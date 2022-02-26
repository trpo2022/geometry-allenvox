#include "circle.h"
#include <math.h>
float calculateCirclePerimeter(float radius)
{
    return 2 * M_PI * radius;
}

float calculateCircleArea(float radius)
{
    return M_PI * radius * radius;
}