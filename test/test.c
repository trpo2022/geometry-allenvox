#include <ctest.h>
#include "geometry/object.h"
#include "libgeometry/circle.h"
#include "libgeometry/point.h"
#include "libgeometry/triangle.h"

// circle
CTEST(check_object_circle, correct)
{
    char correct_input[32] = "circle(1 0, 6)";
    char *token;
    const int expected = 0;
    const int result = check_object(correct_input, &token);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_object_circle, incorrect)
{
    char correct_input[32] = "circle(1 0, 6)";
    char *token;
    const int expected = 0;
    const int result = check_object(correct_input, &token);
    ASSERT_EQUAL(expected, result);
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
}

// triangle
CTEST(check_object_triangle, correct)
{
    char correct_input[32] = "triangle(0 0, 2 2, 3 -2, 0 0)";
    char *token;
    const int expected = 1;
    const int result = check_object(correct_input, &token);
    ASSERT_EQUAL(expected, result);
}