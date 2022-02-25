#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char prefix[] = "(geometry) ";
    char input[64];

    printf("%s", prefix);
    scanf("%[^\n]", &input);

    char delims[] = "( ,)";
    char* token = strtok(input, delims);

    if (strcmp(token, "circle") == 0) {
    } else if (strcmp(token, "triangle") == 0) {
    } else {
        printf("Incorrect input.\n");
    }

    return 0;
}