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

    return 0;
}