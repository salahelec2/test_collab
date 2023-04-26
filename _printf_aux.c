#include "main.h"

/**
 * _print_aux - recieve format and args and print according to format
 * @format: string containing characters and format specifiers
 * @args: list of arguments
 * @print_sym: print function list
 * Return: number of printed chars (excluding the null byte)
 */

int _print_aux(const char *format, va_list args, print_sym_func *print_sym)
{
int i, j, pr_count = 0, total_print_count = 0;

for (i = 0; format[i] != '\0'; i++, total_print_count++)
{
	if (format[i] == '%')
	{
		if (format[i + 1] == '%' || format[i + 1] == 'c')
			_putchar(format[i + 1] == '%' ? '%' : va_arg(args, int));
		else
		{
			for (j = 0; print_sym[j].type != NULL; j++)
			{
				if (format[i + 1] == print_sym[j].type[0])
				{
					pr_count = print_sym[j].f(args);
					if (pr_count == -1)
						return (-1);
					total_print_count += pr_count - 1;
					break;
				}
			}
			if (print_sym[j].type == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
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
return (total_print_count);
}
