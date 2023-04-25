#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list);
int print_integer(va_list);

#endif /* MAIN_H */
