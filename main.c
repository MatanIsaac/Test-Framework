#include "example_code_to_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_framework.h"
#include "logger.h"

void test_string_functions();

int main(void)
{
    test_string_functions();    

    return 0;
}

/* =======================
   Test: String Allocation Functions
   ======================= */
void test_string_functions()
{
    char temp1[10];
    char temp2[10];
    char* str = NULL;
    char* dup = NULL;
   
    char* first_char_test1 = malloc(6);
    char* first_char_test2 = malloc(3);
    if (!first_char_test1 || !first_char_test2) 
    {
        log_error(__FILE__,__LINE__, "Failed to allocate memory for first_char_test variables.");
        free(first_char_test1);
        free(first_char_test2);
        return;
    }
   
    snprintf(first_char_test1, 6, "%s", "#3562");
    snprintf(first_char_test2, 3, "%s", "r6");
   
    log_out(__FILE__, __LINE__, "Starting Test - string memory allocation functions in main.c\n");
   
    str = string_malloc(10);
    if (str) 
    {
        log_test("Test_string_malloc", TEST_PASS, "Allocated memory successfully.");
        free(str);
    } 
    else
        log_test("Test_string_malloc", TEST_FAIL, "Memory allocation failed.");

    str = string_calloc(5, sizeof(char));
    if (str) 
    {
        log_test("Test_string_calloc", TEST_PASS, "Allocated and zero-initialized memory successfully.");
        free(str);
    } 
    else 
        log_test("Test_string_calloc", TEST_FAIL, "Memory allocation failed.");
    
    dup = my_strdup("Hello");
    if (dup) 
    {
        if (strcmp(dup, "Hello") == 0) 
        {
            log_test("Test_my_strdup", TEST_PASS, "Duplicated string correctly.");
            free(dup);
        } 
        else
        {
            log_test("Test_my_strdup", TEST_FAIL, "String duplication incorrect.");
            free(dup);
        }
        
        
    } 
    else 
        log_test("Test_my_strdup", TEST_FAIL, "String duplication failed.");
   
    strcpy(temp1, "MAIN:");
    remove_last_character(temp1);
    log_test("Test_remove_last_character", 
             strcmp(temp1, "MAIN") == 0 ? TEST_PASS : TEST_FAIL, 
             "Removing string's last character.");
   
    strcpy(temp2, "r3,");
    remove_last_character(temp2);
    log_test("Test_remove_last_character", 
             strcmp(temp2, "r3") == 0 ? TEST_PASS : TEST_FAIL, 
             "Removing string's last character.");
   
    remove_first_character(first_char_test1);
    log_test("Test_remove_first_character", 
             strcmp(first_char_test1, "3562") == 0 ? TEST_PASS : TEST_FAIL, 
             "Removing string's first character.");
   
    remove_first_character(first_char_test2);
    log_test("Test_remove_first_character", 
             strcmp(first_char_test2, "6") == 0 ? TEST_PASS : TEST_FAIL, 
             "Removing string's first character.");
   
    log_out(__FILE__, __LINE__, "Done Testing - string memory allocation functions in main.c\n");
   
    free(first_char_test1);
    free(first_char_test2);
}