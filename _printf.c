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

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	total_print_count = _print_aux(format, args);

	va_end(args);
	return (total_print_count);
}
