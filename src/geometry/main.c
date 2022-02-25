#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.141592653589

struct Point {
    float x, y;
};

float calculateSide(struct Point point1, struct Point point2)
{
    float x1 = point1.x, x2 = point2.x;
    float y1 = point1.y, y2 = point2.y;
    return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float calculateCirclePerimeter(float radius)
{
    return 2 * PI * radius;
}

float calculateCircleArea(float radius)
{
    return PI * radius * radius;
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

int main()
{
    char prefix[] = "(geometry) ";
    char input[32];

    printf("%s", prefix);
    scanf("%[^\n]", &input);

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