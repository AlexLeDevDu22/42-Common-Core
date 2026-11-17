/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:24:25 by agarin            #+#    #+#             */
/*   Updated: 2026/11/17 17:55:23 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int	strl;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (!*str)
		return (0);
	strl = ft_strlen(str);
	write(1, str, strl);
	return (strl);
}

int	ft_print_base(long long integer, char *base)
{
	int	n;
	int	base_s;

	base_s = ft_strlen(base);
	n = 0;
	if (integer == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (integer < 0)
	{
		write(1, "-", 1);
		integer = -integer;
		n++;
	}
	if (integer >= base_s)
		n += 1 + ft_print_base(integer / base_s, base);
	else
		n++;
	write(1, base + integer % base_s, 1);
	integer /= base_s;
	return (n);
}

int	ft_print_unsigned_base(unsigned long long integer, char *base)
{
	int				n;
	unsigned int	base_s;

	base_s = ft_strlen(base);
	n = 0;
	if (integer == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (integer >= base_s)
		n += 1 + ft_print_unsigned_base(integer / base_s, base);
	else
		n++;
	write(1, base + integer % base_s, 1);
	integer /= base_s;
	return (n);
}

int	ft_print_pointer(unsigned long long deci)
{
	if (deci == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_print_unsigned_base(deci, "0123456789abcdef"));
}
