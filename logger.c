#include "logger.h"

void log_out(const char *file, int line, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    fprintf(stdout, "[LOG] File: %s | Line: %d | Date: %s | Time: %s\n",
            file, line, __DATE__, __TIME__);
    fprintf(stdout, "\tINFO: ");
    vfprintf(stdout, fmt, args);

    va_end(args);
}

void log_error(const char *file, int line, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "[LOG] File: %s | Line: %d | Date: %s | Time: %s\n",
            file, line, __DATE__, __TIME__);
    fprintf(stderr, "\tERROR: ");
    vfprintf(stderr, fmt, args);

    va_end(args);
}
