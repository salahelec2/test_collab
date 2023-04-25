#include "main.h"

/**
 * _printf - duplicate functionality of printf
 * @format: string containing characters and format specifiers
 * @...: arguments to be printed according to format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, print_count = 0, total_print_count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++, total_print_count++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%' || format[i + 1] == 'c')
				_putchar(format[i + 1] == '%' ? '%' : va_arg(args, int));
			else if (format[i + 1] == 's')
			{
				print_count = print_string(args);
				if (print_count == -1)
					return (-1);
				total_print_count += print_count - 1;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				print_count = print_integer(args);
				if (print_count == -1)
					return (-1);
				total_print_count += print_count - 1;
			}
			else if (format[i + 1] != ' ' && format[i + 1] != '\0')
			{
				_putchar(format[i]);
				_putchar(format[i + 1]);
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
