#include "intersection.h"
#include "circle.h"
#include "triangle.h"
#include <math.h>
#include <stdlib.h>

int circleIntersectsCircle(struct Circle c1, struct Circle c2)
{
    float xDiversity = c1.center.x - c2.center.x;
    float yDiversity = c1.center.y - c2.center.y;
    float radiusesSum = c1.radius + c2.radius;

    float distancesSquared = xDiversity * xDiversity + yDiversity * yDiversity;
    float radiusesSumSquared = radiusesSum * radiusesSum;

    if (distancesSquared > radiusesSumSquared) {
        return -1;
    } else {
        return 0;
    }
}

int circleIntersectsTriangle(struct Circle circle, struct Triangle triangle)
{
    for (int i = 0; i < 3; i++) {
        float a = triangle.points[i].y - triangle.points[i + 1].y;
        float b = triangle.points[i + 1].x - triangle.points[i].x;
        float c = triangle.points[i].x * triangle.points[i + 1].y
                - triangle.points[i + 1].x * triangle.points[i].y;

        float absolute = fabsf(a * circle.center.x + b * circle.center.y + c);
        float squareRoot = sqrt(a * a + b * b);
        float distance = absolute / squareRoot;

        if (circle.radius >= distance) {
            return 0;
        }
    }
    return -1;
}

int onLine(struct Point p1, struct Point p2, struct Point p3)
{
    if (p2.x <= fmax(p1.x, p3.x) && p2.x >= fmin(p1.x, p3.x)
        && p2.y <= fmax(p1.y, p3.y) && p2.y >= fmin(p1.y, p3.y)) {
        return 0;
    } else {
        return -1;
    }
}

int orientation(struct Point p1, struct Point p2, struct Point p3)
{
    int val = (p2.y - p1.x) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) {
        return 0; // collinear
    }
    return (val > 0) ? 1 : 2; // 1 = clockwise, 2 = counterclockwise
}

int triangleIntersectsTriangle(struct Triangle t1, struct Triangle t2)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            struct Point p1 = t1.points[i], q1 = t1.points[i + 1];
            struct Point p2 = t2.points[j], q2 = t2.points[j + 1];

            int o1 = orientation(p1, q1, p2);
            int o2 = orientation(p1, q1, q2);
            int o3 = orientation(p2, q2, p1);
            int o4 = orientation(p2, q2, q1);

            if (o1 != o2 && o3 != o4)
                return 0;
            if (o1 == 0 && onLine(p1, p2, q1))
                return 0;
            if (o2 == 0 && onLine(p1, q2, q1))
                return 0;
            if (o3 == 0 && onLine(p2, p1, q2))
                return 0;
            if (o4 == 0 && onLine(p2, q1, q2))
                return 0;
        }
    }
    return -1;
}