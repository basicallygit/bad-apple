#include "truncate.h"
#include <string.h>
#include <stdlib.h>

char* strtrunc(const char* string, int len)
{
    int length = strlen(string);
    char* temp = (char*)malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++) {
	temp[i] = string[i];
    }
    temp[length] = '\0';
    if (len < strlen(string)) {
	temp[len] = '\0';
    }
    return temp;
}

