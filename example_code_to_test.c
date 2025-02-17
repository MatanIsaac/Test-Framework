#include "example_code_to_test.h"
#include <stdlib.h>
#include <string.h>

char* string_calloc(size_t element_count,size_t size_of_element)
{
    char* str = calloc(element_count,size_of_element);
    if(str == NULL)
    {
        perror("String memory allocation failed\n");
        return NULL;
    }
    return str;
}

char* string_malloc(size_t size)
{
    char* str = (char*)malloc(size);
    if(str == NULL)
    {
        perror("String memory allocation failed\n");
        return NULL;
    }
    return str;
}

char* my_strdup(const char* s) 
{
    size_t len;
    char *copy = NULL;

    if (s == NULL) 
        return NULL;

    len = strlen(s) + 1;
    copy = malloc(len);

    if (copy) 
    {
        memcpy(copy, s, len);
    }
    return copy;
}

void remove_last_character(char *s)
{
    int len = strlen(s);

    if (!s || len == 0)
        return;

    s[len-1] = '\0';
}

void remove_first_character(char* s)
{
    int i = 1;
    int len = strlen(s);

    if (!s || len == 0)
        return;

    while(i < len)
    {    
        s[i-1] = s[i]; 
        i++;
    }
    s[len-1] = '\0';
}