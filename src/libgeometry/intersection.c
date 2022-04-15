#include "intersection.h"
#include "circle.h"
#include "triangle.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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
    int centrex = circle.center.x;
    int centrey = circle.center.y;

    int c1x = centrex - triangle.points[0].x;
    int c1y = centrey - triangle.points[0].y;

    int radiusSqr = circle.radius * circle.radius;
    int c1sqr = c1x*c1x + c1y*c1y;

    if(c1sqr <= radiusSqr) {
        return 0;
    }

    int c2x = centrex - triangle.points[1].x;
    int c2y = centrey - triangle.points[1].y;
    int c2sqr = c2x*c2x + c2y*c2y;

    if(c2sqr <= radiusSqr) {
        return 0;
    }

    int c3x = centrex - triangle.points[2].x;
    int c3y = centrey - triangle.points[2].y;
    int c3sqr = c3x*c3x + c3y*c3y;

    if(c3sqr <= radiusSqr) {
        return 0;
    }

    int e1x = triangle.points[1].x - triangle.points[0].x;
    int e1y = triangle.points[1].y - triangle.points[0].y;

    int e2x = triangle.points[2].x - triangle.points[1].x;
    int e2y = triangle.points[2].y - triangle.points[1].y;

    int e3x = triangle.points[3].x - triangle.points[2].x;
    int e3y = triangle.points[3].y - triangle.points[2].y;

    if (e1y*c1x - e1x*c1y >= 0 && e2y*c2x - e2x*c2y >= 0 && e3y*c3x - e3x*c3y >= 0) {
        return 0;
    }

    int k = c1x*e1x + c1y*e1y;
    int len = 0;

    if(k > 0) {
        len = e1x*e1x + e1y*e1y;
        k = k*k/len;

        if(k < len) {
            if(c1sqr - k <= radiusSqr) {
                return 0;
            }
        }
    }

    k = c2x*e2x + c2y*e2y;

    if(k > 0) {
        len = e2x*e2x + e2y*e2y;
        k = k*k/len;

        if(k < len) {
            if(c2sqr - k <= radiusSqr) {
                return 0;
            }
        }
    }

    k = c3x*e3x + c3y*e3y;

    if(k > 0) {
        len = e3x*e3x + e3y*e3y;
        k = k*k/len;
        if(k < len) {
            if(c3sqr - k <= radiusSqr) {
                return 0;
            }
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

void intersections(object objects[3]) {
    printf("Intersections:\n");
    for(int i = 0; i < 2; i++) {
        for(int k = 1; k < 3; k++) {
            if(i == k) continue;
            if(objects[i].type == CIRCLE && objects[k].type == CIRCLE) {
                if(circleIntersectsCircle(objects[i].circle, objects[k].circle) == 0) {
                    printf("\t%d. circle intersects %d. circle\n", i+1, k+1);
                }
            } else if (objects[i].type == TRIANGLE && objects[k].type == CIRCLE) {
                if(circleIntersectsTriangle(objects[k].circle, objects[i].triangle) == 0) {
                    printf("\t%d. triangle intersects %d. circle\n", i+1, k+1);
                }
            } else if (objects[i].type == CIRCLE && objects[k].type == TRIANGLE) {
                if(circleIntersectsTriangle(objects[i].circle, objects[k].triangle) == 0) {
                    printf("\t%d. circle intersects %d. triangle\n", i+1, k+1);
                }
            } else if (objects[i].type == TRIANGLE && objects[k].type == TRIANGLE) {
                if(triangleIntersectsTriangle(objects[i].triangle, objects[k].triangle) == 0) {
                    printf("\t%d. triangle intersects %d. triangle\n", i+1, k+1);
                }
            }
        }
    }
}