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

    } else if (strcmp(token, "triangle") == 0) {
        struct Point points[4];

    } else {
        printf("Incorrect input.\n");
    }

    return 0;
}