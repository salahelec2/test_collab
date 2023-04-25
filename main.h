#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/* #define NULL_STRING "(null)"
#define NUL '\0' */

/**
 * struct convert - defines a structure for symbols and functions
 *
 * @sym: The operator
 * @f: The function associated
 */

typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} convert_struct;

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int format_reciever(const char *format, va_list arg_list);
int print_string(va_list);

#endif
