/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:19:46 by agarin            #+#    #+#             */
/*   Updated: 2026/11/17 17:50:25 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isarg(char *str)
{
	char	*avchrs;

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
		return (ft_print_c((char)va_arg(args, int)));
	if (type == 's')
		return (ft_print_s(va_arg(args, char *)));
	if (type == 'p')
		return (ft_print_pointer((unsigned long long)va_arg(args, void *)));
	if (type == 'd')
		return (ft_print_base(va_arg(args, int), "0123456789"));
	if (type == 'i')
		return (ft_print_base(va_arg(args, int), "0123456789"));
	if (type == 'u')
		return (ft_print_unsigned_base((unsigned int)va_arg(args, int),
				"0123456789"));
	if (type == 'x')
		return (ft_print_unsigned_base(va_arg(args, unsigned int),
				"0123456789abcdef"));
	if (type == 'X')
		return (ft_print_unsigned_base(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	if (type == '%')
		return (ft_print_c('%'));
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
