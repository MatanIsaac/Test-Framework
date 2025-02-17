#ifndef EXAMPLE_CODE_TO_TEST_H
#define EXAMPLE_CODE_TO_TEST_H
#include <stdio.h>

char* string_calloc(size_t element_count,size_t size_of_element);
char* string_malloc(size_t size);
char* my_strdup(const char* src);
void remove_last_character(char* s);
void remove_first_character(char* s);

#endif