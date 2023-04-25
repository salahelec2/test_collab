#include "main.h"

/**
 * print_integer - prints an integer from a va_list
 * @args: list of arguments
 * Return: number of printed chars (excluding the null byte)
 */

int print_integer(va_list args)
{
	int length = 0;
	int digit = 1;
	int num = va_arg(args, int);

	if (num < 0)
	{
		_putchar('-');
		length++;
		num *= -1;
	}
	while (num / digit > 9)
		digit *= 10;

	while (digit)
	{
		length += _putchar('0' + num / digit);
		num %= digit;
		digit /= 10;
	}

	return (length);
}