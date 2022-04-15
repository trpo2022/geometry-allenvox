#include "circle.h"
#include "point.h"
#include <math.h>
#include <stdio.h>

float calculateCirclePerimeter(float radius)
{
    return 2 * M_PI * radius;
}

float calculateCircleArea(float radius)
{
    return M_PI * radius * radius;
}

void printCircleInfo(struct Circle circle)
{
    printf("\tcenter = (%.3f %.3f)\n\tradius = %.6f\n\tperimeter = "
           "%.6f\n\tarea = %.6f\n\n",
           circle.center.x,
           circle.center.y,
           circle.radius,
           calculateCirclePerimeter(circle.radius),
           calculateCircleArea(circle.radius));
}