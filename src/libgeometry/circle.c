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

void printCircleInfo(
        float x, float y, float radius, float perimeter, float area)
{
    char* figure = "circle";
    printf("\n%s:\n\tcenter = (%.3f %.3f)\n\tradius = %.3f\n\tperimeter = "
           "%.3f\n\tarea = %.3f\n\n",
           figure,
           x,
           y,
           radius,
           perimeter,
           area);
}