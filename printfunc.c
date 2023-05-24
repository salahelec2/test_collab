#include "main.h"

/**
 *_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - functiont to write strinng to standard out
 * @str: string to write
 */

void _puts(char *str)
{
	while (*str  != '\0')
	{
		write(1, str, 1);
		str++;
	}
}