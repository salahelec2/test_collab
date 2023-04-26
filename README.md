# _printf Function

The `_printf` function is a custom implementation of the standard C `printf` function. This function takes a format string and any additional arguments, formats them according to the format string, and then prints the resulting string to the standard output.

## Files

The following files are included in this repository:

- `_printf.c`: The main function for the `_printf` implementation
- `_putchar.c`: A helper function for printing characters to the standard output
- `main.h`: The header file for the `_printf` function
- `print_integer.c`: A helper function for printing integers
- `print_string.c`: A helper function for printing strings

## Usage

The `_printf` function can be used in the same way as the standard C `printf` function. Here is an example:

```c
#include "main.h"

int main(void)
{
    int a = 123;
    char c = 'H';
    char *str = "HELLO WORLD!";
    
    _printf("An integer: %d\n", a);
    _printf("An integer: %i\n", a);
    _printf("A char: %c\n", c);
    _printf("A String: %s\n", s);
    _printf("A percent char: %%\n");
    
    return (0);
}
