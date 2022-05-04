#pragma once
#include "circle.h"
#include "object.h"
#include "triangle.h"
int circleIntersectsCircle(struct Circle c1, struct Circle c2);
int circleIntersectsTriangle(struct Circle circle, struct Triangle triangle);
int triangleIntersectsTriangle(struct Triangle t1, struct Triangle t2);
int orientation(struct Point p1, struct Point p2, struct Point p3);
int onLine(struct Point p1, struct Point p2, struct Point p3);
void intersections(object objects[3]);