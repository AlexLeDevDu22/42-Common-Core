#include <stdarg.h>
#include <unistd.h>

//#include "ft_printf_formats.c"

int ft_printf(const char *, ...);

int ft_print_c(va_list args);
int ft_print_s(va_list args);
int ft_print_base(int deci, char *base);

int ft_strlen(char *);