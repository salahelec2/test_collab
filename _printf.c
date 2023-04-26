#include "main.h"

/**
 * _printf - duplicate functionality of printf
 * @format: string containing characters and format specifiers
 * @...: arguments to be printed according to format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, j, pr_count = 0, total_print_count = 0, next;
	va_list args;
	print_sym_func print_sym[] = {
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}};

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
			else
			{
				for (j = 0; print_sym[j].type != NULL; j++)
				{
					if (next == print_sym[j].type[0])
					{
						pr_count = print_sym[j].f(args);
						if (pr_count == -1)
							return (-1);
						total_print_count += pr_count - 1;
						break;
					}
				}
				if (print_sym[j].type == NULL && next != ' ')
				{
					if (next != '\0')
					{
						_putchar(format[i]);
						_putchar(next);
						total_print_count++;
					}
					else
						return (-1);
				}
			}

			i++;
		}
		else
			_putchar(format[i]);
	}
	va_end(args);
	return (total_print_count);
}
