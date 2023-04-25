#include "main.h"

/**
 * _putchar - print a char to terminal
 * @c: char to be printed
 *
 * Return: number of chars printed on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
