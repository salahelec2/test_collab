#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct print - defines a structure for symbols and print functions
 *
 * @type: formating type
 * @f: The function associated
 */

typedef struct print
{
	char *type;
	int (*f)(va_list);
} print_sym_func;

print_sym_func *init_print_sym(void);

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list);
int print_integer(va_list);
int print_binary(va_list);
int _print_aux(const char *format, va_list args, print_sym_func *print_sym);

#endif /* MAIN_H */
