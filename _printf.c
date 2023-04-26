#include "main.h"

/**
 * _printf - duplicate functionality of printf
 * @format: string containing characters and format specifiers
 * @...: arguments to be printed according to format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int total_print_count = 0;
	print_sym_func *print_sym = init_print_sym();

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	total_print_count = _print_aux(format, args, print_sym);

	va_end(args);
	free(print_sym);
	return (total_print_count);
}
