#include "main.h"

/**
 * print_string - prints a string
 * @args: args list for string to be printed
 * Return: number of printed chars
 */

int print_string(va_list args)
{
	int i;
	char *string;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
	return (i);
}
