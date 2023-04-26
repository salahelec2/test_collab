#include "main.h"

/**
 * _printf - duplicate functionality of printf
 * @format: string containing characters and format specifiers
 * @...: arguments to be printed according to format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, pr_count = 0, total_print_count = 0, next;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++, total_print_count++)
	{
		if (format[i] == '%')
		{
			next = format[i + 1];
			if (next == '%' || next == 'c')
				_putchar(next == '%' ? '%' : va_arg(args, int));
			else if (next == 's' || next == 'd' || next == 'i')
			{
				pr_count = next == 's' ? print_string(args) : print_integer(args);
				if (pr_count == -1)
					return (-1);
				total_print_count += pr_count - 1;
			}
			else if (next != ' ' && next != '\0')
			{
				_putchar(format[i]);
				_putchar(next);
				total_print_count++;
			}
			else
				return (-1);
			i++;
		}
		else
			_putchar(format[i]);
	}
	va_end(args);
	return (total_print_count);
}

