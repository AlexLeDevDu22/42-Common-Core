/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:50:52 by agarin            #+#    #+#             */
/*   Updated: 2026/11/17 17:54:28 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_print_c(char c);
int	ft_print_s(char *str);
int	ft_print_base(long long integer, char *base);
int	ft_print_unsigned_base(unsigned long long integer, char *base);
int	ft_print_pointer(unsigned long long deci);

int	ft_strlen(char *str);

#endif
