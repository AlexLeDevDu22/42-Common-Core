*This activity has been created as part of the 42 curriculum by agarin.*

# ft_printf

## Description

The **ft_printf** project is part of the 42 curriculum. Its goal is to recreate the behavior of the standard C `printf()` function.

The main objective is to understand and implement variadic functions in C using `va_start`, `va_arg` and `va_end`.

This project provides a custom library called `libftprintf.a`, containing the `ft_printf()` function.

The implementation handles different format specifiers and prints the corresponding arguments to the standard output.

## Features

The mandatory conversions implemented by this project are:

| Conversion | Description |
|:---:|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a hexadecimal number in lowercase. |
| `%X` | Prints a hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

To compile the library, clone the repository and run:

```bash
make
```

This generates the static library:

```bash
libftprintf.a
```

### Makefile rules

The Makefile provides the following rules:

| Command | Description |
|---|---|
| `make` | Compiles the library. |
| `make all` | Builds the library. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the library. |
| `make re` | Recompiles everything from scratch. |

### Usage

Include the header file in your C project:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf -o program
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Percentage: %%\n");

    return (0);
}
```

## Implementation

### Variadic functions

The main function is:

```c
int ft_printf(const char *format, ...);
```

It uses variadic arguments to accept a variable number of parameters.

The following macros are used:

- `va_start`: initializes the argument list.
- `va_arg`: retrieves the next argument.
- `va_end`: closes the argument list.

### Format parsing

The function iterates through the format string character by character.

When it encounters `%`, it checks the next character to identify the conversion type.

The `ft_isarg()` function checks whether the character corresponds to a supported conversion.

If the conversion is valid, `ft_handle_arg()` dispatches the argument to the appropriate printing function.

Otherwise, the character is printed directly.

### Printing functions

The project separates the printing logic into several functions:

- `ft_print_c()`: prints a character.
- `ft_print_s()`: prints a string.
- `ft_print_base()`: prints signed numbers using a given base.
- `ft_print_unsigned_base()`: prints unsigned numbers using a given base.
- `ft_print_pointer()`: prints memory addresses in hexadecimal format.

### Algorithm and data structures

The implementation relies on a sequential traversal of the format string and uses recursion to print numbers in different bases.

**Format parsing:**

The format string is processed from left to right. Each character is examined individually.

When a conversion specifier is found, the corresponding argument is retrieved and passed to its dedicated printing function.

**Number conversion using recursion:**

The functions `ft_print_base()` and `ft_print_unsigned_base()` use a recursive algorithm.

The algorithm works as follows:

1. Calculate the length of the base.
2. Divide the number by the base length.
3. Recursively print the quotient.
4. Print the remainder using the corresponding character from the base string.

This ensures that digits are printed in the correct order, from the most significant digit to the least significant digit.

For example, the decimal number `255` converted to hexadecimal follows these steps:

- 255 / 16 = 15, remainder 15.
- 15 / 16 = 0, remainder 15.
- The hexadecimal representation is `ff`.

**Data structures:**

No complex data structures are required. The implementation mainly uses:

- Character strings to represent format strings and numerical bases.
- `va_list` to manage variadic arguments.
- Integer variables to track the number of printed characters.

This approach keeps the implementation relatively simple and modular.

## Resources

The following resources were useful for understanding the concepts involved in this project:

- [Linux manual – printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux manual – stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [C documentation – Variadic functions](https://en.cppreference.com/w/c/variadic.html)
- [42 School](https://42.fr/)

### AI Usage

AI tools were used as a learning and assistance resource during this project.

They were used for:
- Understanding the requirements of the ft_printf assignment.
- Creating the README documentation.
- Identifying potential issues and improvements in the implementation.
- Clarifying concepts related to variadic functions and recursive number conversion.

The implementation and understanding of the code remain the responsibility of the student. All code must be understood and explainable during peer evaluations.

---

**Author:** agarin  
**School:** 42