#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

void log_out(const char *file, int line, const char *fmt, ...);
void log_error(const char *file, int line, const char *fmt, ...);

#endif
