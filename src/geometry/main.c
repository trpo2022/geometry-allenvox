#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point {
    float x, y;
};

int main()
{
    char prefix[] = "(geometry) ";
    char input[64];

    printf("%s", prefix);
    scanf("%[^\n]", &input);

    char delims[] = "( ,)";
    char* token = strtok(input, delims);

    if (strcmp(token, "circle") == 0) {
        struct Point point;

        point.x = atof(strtok(NULL, delims));
        point.y = atof(strtok(NULL, delims));
        float radius = atof(strtok(NULL, delims));

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

    } else {
        printf("Incorrect input.\n");
    }

    return 0;
}