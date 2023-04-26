#include "main.h"

/**
 * print_aux - recieve format and args and print according to format
 * @format: string containing characters and format specifiers
 * @args: list of arguments
 * Return: number of printed chars (excluding the null byte)
 */

int _print_aux(const char *format, va_list args)
{
    int i, j, pr_count = 0, total_print_count = 0, next;
    print_sym_func *print_sym = init_print_sym();

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
    free(print_sym);
    return (total_print_count);
}