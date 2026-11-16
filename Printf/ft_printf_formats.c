/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:24:25 by agarin            #+#    #+#             */
/*   Updated: 2026/11/16 21:15:01 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_c(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int ft_print_s(va_list args)
{
	char *str;
	int strl;

	str = (char *)va_arg(args, char *);
	strl = ft_strlen(str);
	write(1, str, strl);
	return (strl);
}

int ft_print_base(int deci, char *base)
{
	int n;
	int base_s;

	base_s = ft_strlen(base);
	n = 0;
	if (deci == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (deci < 0)
	{
		write(1, "-", 1);
		deci = -deci;
		n++;
	}
	if (deci >= 16)
		n += 1 + ft_print_base(deci / base_s, base);
	else
		n++;
	write(1, "0123456789abcdef" + deci % base_s, 1);
	deci /= 16;
	return (n);
}
