#include "triangle.h"
#include "point.h"
#include "stdio.h"
#include <math.h>

float calculateSide(struct Point point1, struct Point point2)
{
    float x1 = point1.x, x2 = point2.x;
    float y1 = point1.y, y2 = point2.y;
    return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float calculateTrianglePerimeter(struct Point points[4])
{
    float sides[3];
    float perimeter = 0;
    for (int i = 0; i < 3; i++) {
        sides[i] = calculateSide(points[i], points[i + 1]);
        perimeter += sides[i];
    }
    return perimeter;
}

float calculateTriangleArea(struct Point points[4])
{
    float semiperimeter = calculateTrianglePerimeter(points) / 2;
    float area = semiperimeter;
    for (int i = 0; i < 3; i++) {
        area *= semiperimeter - calculateSide(points[i], points[i + 1]);
    }
    return sqrtf(area);
}