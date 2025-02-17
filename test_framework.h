#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <time.h>
#include "logger.h"

typedef enum 
{
    TEST_PASS,    /* The test passed successfully */
    TEST_FAIL,    /* The test failed  */
    TEST_OTHER    /* Any other non-pass/fail result (e.g., skipped, error, timeout, crash)  */
} TestResultType;

/* Function to convert TestResultType to a string */
const char* test_result_to_string(TestResultType result) 
{
    switch (result) 
    {
        case TEST_PASS:  return "PASS";
        case TEST_FAIL:  return "FAIL";
        case TEST_OTHER: return "OTHER";
        default:         return "UNKNOWN";
    }
}

/* Function to log test results */
void log_test(const char* test_name, TestResultType result, const char* details) 
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    
    log_out(__FILE__,__LINE__,"  [%s]\n\tTest:   [%s]\n"
           "\tResult:   [%s]\n"
           "\tDetails:  [%s]\n\n",
           timestamp, test_name, test_result_to_string(result), details ? details : "N/A");
}

#endif
