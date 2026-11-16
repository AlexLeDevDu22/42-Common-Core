/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:19:46 by agarin            #+#    #+#             */
/*   Updated: 2026/11/16 21:15:34 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_isarg(char *str)
{
	char *avchrs;
	avchrs = "cspdiuxX%";
	
	if (*str != '%')
		return (0);
	str++;
	if (!str)
		return (0);
	while (*avchrs && *str != *avchrs)
		avchrs++;
	return (*avchrs);
}

int	ft_handle_arg(char type, va_list args)
{
	if (type == 'c')
		ft_print_c(args);
	else if (type == 's')
		ft_print_s(args);
	if (type == 'p')
		ft_print_base(va_arg(args, int), "0123456789abcdef");
	if (type == 'd')
		ft_print_base(va_arg(args, float), "0123456789");
	if (type == 'i')
		ft_print_base(va_arg(args, int), "0123456789");
	// if (type == 'u')
	// if (type == 'x')
	// if (type == 'X')
	// if (type == '%')
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		n;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	n = 0;
	while (*format)
	{
		if (ft_isarg((char *)format))
		{
			n += ft_handle_arg(format[1], args);
			format++;
		}
		else
		{
			write(1, format, 1);
			n++;
		}
		format++;
	}
	va_end(args);
	return (n);
}

int main()
{
	ft_printf("%d\n", "");
}