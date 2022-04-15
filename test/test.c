#include <ctest.h>
#include "libgeometry/object.h"
#include "libgeometry/circle.h"
#include "libgeometry/point.h"
#include "libgeometry/triangle.h"
#include "libgeometry/intersection.h"
#include <string.h>
#include <stdlib.h>

#define DELIMS "( ,)"

CTEST(check_object_circle, correct)
{
    char input[32] = "circle(1 0, 6)\0";
    char *token;
    const int expected = 0;
    const int result = check_object(input, &token);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_object_circle, incorrect_input_1)
{
    char input[32] = "cicle(1 0, 6)\0";
    char *token;
    const int expected = 0;
    const int result = check_object(input, &token);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(check_object_circle, incorrect_input_2)
{
    char input[32] = " cle(1 0, 6)\0";
    char *token;
    const int expected = 0;
    const int result = check_object(input, &token);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(check_object_circle, incorrect_input_3)
{
    char input[32] = "circol(1 0, 6)\0";
    char *token;
    const int expected = 0;
    const int result = check_object(input, &token);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(check_object_circle, incorrect_input_4)
{
    char input[32] = "circlee(1 0, 6)\0";
    char *token;
    const int expected = 0;
    const int result = check_object(input, &token);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(check_object_circle, incorrect_input_5)
{
    char input[32] = "(0 0, 6)\0";
    char *token;
    const int expected = 0;
    const int result = check_object(input, &token);
    CTEST_LOG("check object circle end");
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(calculate_circle_perimeter, correct)
{   
    float radius = 6;
    const float expected = 37;
    const float result = calculateCirclePerimeter(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(calculate_circle_area, correct)
{
    float radius = 6;
    const float expected = 113;
    const float result = calculateCircleArea(radius);
    ASSERT_EQUAL(expected, result);
    CTEST_LOG("circle calculations end");
}

CTEST(calculate_triangle_perimeter, correct)
{
    struct Point points[4] = {{0,0},{2,2},{3,-2},{0,0}};
    const float expected = 10.5;
    const float result = calculateTrianglePerimeter(points);
    ASSERT_EQUAL(expected, result);
}

CTEST(calculate_triangle_area, correct)
{
    struct Point points[4] = {{0,0},{2,2},{3,-2},{0,0}};
    const float expected = 4.999998;
    const float result = calculateTriangleArea(points);
    ASSERT_EQUAL(expected, result);
    CTEST_LOG("triangle calculations end");
}

CTEST(check_circle_center_x, correct)
{
    char input[32] = "circle(1 0, 6)\0";
    strtok(input, DELIMS);
    const float expected = 1;
    const float result = atof(strtok(NULL, DELIMS));
    ASSERT_EQUAL(expected, result);
}

CTEST(check_circle_center_y, correct)
{
    char input[32] = "circle(1 0, 6)\0";
    strtok(input, DELIMS);
    strtok(NULL, DELIMS);
    const float expected = 0;
    const float result = atof(strtok(NULL, DELIMS));
    ASSERT_EQUAL(expected, result);
}

CTEST(check_circle_radius, correct)
{
    char input[32] = "circle(1 0, 6)\0";
    strtok(input, DELIMS);
    strtok(NULL, DELIMS);
    strtok(NULL, DELIMS);
    const float expected = 6;
    const float result = atof(strtok(NULL, DELIMS));
    ASSERT_EQUAL(expected, result);
    CTEST_LOG("check circle arguments end");
}

CTEST(check_object_triangle, correct)
{
    char input[32] = "triangle(0 0, 2 2, 3 -2, 0 0)\0";
    char *token;
    const int expected = 1;
    const int result = check_object(input, &token);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_object_triangle, incorrect_input_1)
{
    char input[32] = "tiragnel(0 0, 2 2, 3 -2, 0 0)\0";
    char *token;
    const int expected = 1;
    const int result = check_object(input, &token);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(check_object_triangle, incorrect_input_2)
{
    char input[32] = "tirangle(0 0, 2 2, 3 -2, 0 0)\0";
    char *token;
    const int expected = 1;
    const int result = check_object(input, &token);
    ASSERT_NOT_EQUAL(expected, result);
    CTEST_LOG("check object triangle end");
}

CTEST(check_triangle_points, correct)
{
    char input[32] = "triangle(0 1, 2 2, 3 -2, 0 1)\0";
    char *token = strtok(input, DELIMS);
    for(int i = 0; i < 8; i++) {
        token = strtok(NULL, DELIMS);
    }
    const float expected = 1;
    const float result = atof(token);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_triangle_points, incorrect)
{
    char input[32] = "triangle(0 1, 2 2, 3 2, 0 0)\0";
    char *token = strtok(input, DELIMS);
    for(int i = 0; i < 8; i++) {
        token = strtok(NULL, DELIMS);
    }
    const float expected = 1;
    const float result = atof(token);
    ASSERT_NOT_EQUAL(expected, result);
    CTEST_LOG("check triangle points end");
}

CTEST(intersection_circle_circle, correct)
{
    struct Circle c1, c2;
    c1.radius = 1;
    c2.radius = 2;
    c1.center.x = 3;
    c1.center.y = 3;
    c2.center.x = 5;
    c2.center.y = 3;
    const int expected = 0;
    const int result = circleIntersectsCircle(c1, c2);
    ASSERT_EQUAL(expected, result);
}

CTEST(intersection_circle_triangle, correct)
{
    struct Circle c;
    c.radius = 1;
    c.center.x = -2;
    c.center.y = 2;
    struct Triangle t;
    t.points[0].x = -4;
    t.points[0].y = 2;
    t.points[1].x = -3;
    t.points[1].y = 3;
    t.points[2].x = -2;
    t.points[2].y = 2;
    t.points[3].x = -4;
    t.points[3].y = 2;
    const int expected = 0;
    const int result = circleIntersectsTriangle(c, t);
    ASSERT_EQUAL(expected, result);
}

CTEST(intersection_triangle_triangle, correct)
{
    struct Triangle t1, t2;
    t1.points[0].x = -2;
    t1.points[0].y = -4;
    t1.points[1].x = 2;
    t1.points[1].y = -2;
    t1.points[2].x = 3;
    t1.points[2].y = -4;
    t1.points[3].x = -2;
    t1.points[3].y = -4;

    t2.points[0].x = 1;
    t2.points[0].y = -3;
    t2.points[1].x = 3;
    t2.points[1].y = -2;
    t2.points[2].x = 4;
    t2.points[2].y = -4;
    t2.points[3].x = 1;
    t2.points[3].y = -3;
    const int expected = 0;
    const int result = triangleIntersectsTriangle(t1, t2);
    ASSERT_EQUAL(expected, result);
}

CTEST(intersection_circle_circle, incorrect)
{
    struct Circle c1, c2;
    c1.radius = 1;
    c2.radius = 1;
    c1.center.x = -2;
    c1.center.y = 2;
    c2.center.x = 3;
    c2.center.y = 3;
    const int expected = 0;
    const int result = circleIntersectsCircle(c1, c2);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(intersection_circle_triangle, incorrect)
{
    struct Circle c;
    c.radius = 1;
    c.center.x = -2;
    c.center.y = 2;
    struct Triangle t;
    t.points[0].x = 1;
    t.points[0].y = -3;
    t.points[1].x = 3;
    t.points[1].y = -2;
    t.points[2].x = 4;
    t.points[2].y = -4;
    t.points[3].x = 1;
    t.points[3].y = -3;
    const int expected = 0;
    const int result = circleIntersectsTriangle(c, t);
    ASSERT_NOT_EQUAL(expected, result);
}

CTEST(intersection_triangle_triangle, incorrect)
{
    struct Triangle t1, t2;
    t1.points[0].x = -4;
    t1.points[0].y = 2;
    t1.points[1].x = -3;
    t1.points[1].y = 3;
    t1.points[2].x = -2;
    t1.points[2].y = 2;
    t1.points[3].x = -4;
    t1.points[3].y = 2;

    t2.points[0].x = 1;
    t2.points[0].y = -3;
    t2.points[1].x = 3;
    t2.points[1].y = -2;
    t2.points[2].x = 4;
    t2.points[2].y = -4;
    t2.points[3].x = 1;
    t2.points[3].y = -3;
    const int expected = 0;
    const int result = triangleIntersectsTriangle(t1, t2);
    CTEST_LOG("intersections end");
    ASSERT_NOT_EQUAL(expected, result);
}