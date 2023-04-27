#include "main.h"

/**
 * reverse_string - reverses a string
 * @str: string to be reversed
 * Return: pointer to reversed string
 */
char *reverse_string(char *str)
{
	int i, j;
	char *rev_str;

	for (i = 0; str[i] != '\0'; i++)
		;
	rev_str = malloc(sizeof(char) * i + 1);
	if (rev_str == NULL)
		return (NULL);

	for (j = 0; j < i; j++)
		rev_str[j] = str[i - j - 1];

	rev_str[j] = '\0';
	return (rev_str);
}

/**
 * int_to_bin - converts an int to binary
 * @n: int to be converted
 * Return: pointer to binary string
 */
char *int_to_bin(int n)
{
	int binaryNum[33];
	int i = 0, j;
	char *str;

	while (n > 0)
	{
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);

	for (j = i - 1; j >= 0; j--)
		str[j] = binaryNum[j] + '0';

	str[i] = '\0';
	return (reverse_string(str));
}

/**
 * print_binary - prints a binary number
 * @list: va_list with number to be printed
 * Return: number of printed chars
 */
int print_binary(va_list list)
{
	int i;
	char *str;

	str = int_to_bin(va_arg(list, int));

	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}
