#include "main.h"

/**
 * _putchar - print a char to terminal
 * @c: char to be printed
 *
 * Return: On success 1 or -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}



