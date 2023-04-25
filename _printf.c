#include "main.h"

/**
 * _printf - duplicate functionality of printf
 * @format: string containing characters and format specifiers
 * @...: arguments to be printed according to format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, print_count, total_print_count;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	total_print_count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{

			if (format[i + 1] == '%')
			{
				_putchar('%');
				total_print_count++;
			}
			else if (format[i + 1] == 'c')
			{
				_putchar(va_arg(args, int));
				total_print_count++;
			}
			else if (format[i + 1] == 's')
			{
				print_count = print_string(args);
				if (print_count == -1)
					return (-1);
				total_print_count += print_count;
			}

			else if (format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					total_print_count += 2;
				}
				else
					return (-1);
			}

			i++;
		}
		else
		{
			_putchar(format[i]);
			total_print_count++;
		}
	}

	va_end(args);

	return (total_print_count);
}
