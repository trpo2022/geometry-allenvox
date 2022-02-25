#include "circle.h"
#define PI 3.141592653589
float calculateCirclePerimeter(float radius)
{
    return 2 * PI * radius;
}

float calculateCircleArea(float radius)
{
    return PI * radius * radius;
}