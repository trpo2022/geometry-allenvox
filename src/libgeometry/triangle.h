#pragma once
#include "point.h"

struct Triangle {
    struct Point points[4];
};

float calculateSide(struct Point point1, struct Point point2);
float calculateTrianglePerimeter(struct Point points[4]);
float calculateTriangleArea(struct Point points[4]);
void printTriangleInfo(struct Triangle triangle);