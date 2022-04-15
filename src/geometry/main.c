#include "input_read.h"
#include "libgeometry/circle.h"
#include "libgeometry/point.h"
#include "libgeometry/triangle.h"
#include "libgeometry/intersection.h"
#include "libgeometry/object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getObject(int i, object *obj)
{
    char* input = malloc(sizeof(char) * 32);
    char* token = NULL;
    initInput(input);
    char *delims = "( ,)";
    switch (check_object(input, &token)) {
    case 0:
        printf("\n%d. %s:\n", i, token);
        struct Circle circle;

        circle.center.x = atof(strtok(NULL, delims));
        circle.center.y = atof(strtok(NULL, delims));
        circle.radius = atof(strtok(NULL, delims));

        obj->circle = circle;
        obj->type = CIRCLE;
        printCircleInfo(circle);
        break;

    case 1:
        printf("\n%d. %s:\n", i, token);
        struct Triangle triangle;

        for (int i = 0; i < 4; i++) {
            triangle.points[i].x = atof(strtok(NULL, delims));
            triangle.points[i].y = atof(strtok(NULL, delims));
        }

        if (triangle.points[3].x != triangle.points[0].x
            || triangle.points[3].y != triangle.points[0].y) {
            printf("Error with handling the first/last point of the "
                   "triangle.\nCheck if your data is correct.\n");
        }

        obj->triangle = triangle;
        obj->type = TRIANGLE;
        printTriangleInfo(triangle);
        break;

    default:
        printf("Incorrect input.\n");
    }
    free(input);
}

int main()
{
    object objects[3];
    for(int i = 0; i < 3; i++) {
        getObject(i+1, &objects[i]);
    }
    intersections(objects);
    return 0;
}