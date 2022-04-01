#include "object.h"
#include <string.h>

int check_object(char *input, char **token)
{   
    *token = strtok(input, "( ,)");
    if(strcmp(*token, "circle") == 0) {
        return 0;
    } else if(strcmp(*token, "triangle") == 0) {
        return 1;
    }
    return -1;
}