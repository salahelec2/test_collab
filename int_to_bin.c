#include "main.h"

char *int_to_bin(int n)
{
    int binaryNum[32];
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
    return (str);
}

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

int print_binary(va_list list)
{
    char *str;

    str = reverse_string(int_to_bin(va_arg(list, int)));

    return (print_string(str));
}