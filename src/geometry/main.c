#include "input_read.h"
#include <libgeometry/circle.h>
#include <libgeometry/point.h>
#include <libgeometry/triangle.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* input = malloc(sizeof(char) * 32);
    initInput(input);

    char delims[] = "( ,)";
    char* token = strtok(input, delims);

    if (strcmp(token, "circle") == 0) {
        struct Point point;

        point.x = atof(strtok(NULL, delims));
        point.y = atof(strtok(NULL, delims));
        float radius = atof(strtok(NULL, delims));

        float perimeter = calculateCirclePerimeter(radius);
        float area = calculateCircleArea(radius);

        printf("\tperimeter = %.3f\n", perimeter);
        printf("\tarea = %.3f\n", area);

    } else if (strcmp(token, "triangle") == 0) {
        struct Point points[4];

        for (int i = 0; i < 4; i++) {
            points[i].x = atof(strtok(NULL, delims));
            points[i].y = atof(strtok(NULL, delims));
        }

        if (points[3].x != points[0].x || points[3].y != points[0].y) {
            printf("Error with handling the first/last point of the "
                   "triangle.\nCheck if your data is correct.\n");
        }

        float perimeter = calculateTrianglePerimeter(points);
        float area = calculateTriangleArea(points);

        printf("\tperimeter = %.3f\n", perimeter);
        printf("\tarea = %.3f\n", area);

    } else if (strcmp(token, "q") == 0) {
        return 0;

    } else {
        printf("Incorrect input.\n");
    }
    return 0;
}