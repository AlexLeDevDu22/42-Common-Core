/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:25:49 by agarin            #+#    #+#             */
/*   Updated: 2026/11/20 16:44:50 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strchr(const char *s, int c)
{
	if (!s)
		return (nullptr);
	while (*s && *s != (char) c)
		s++;
	if (*s == (char) c)
		return ((char *) s);
    return (nullptr);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t  i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen((char *) src));
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t  dsti;
	size_t  srci;
	size_t  res;

	dsti = 0;
	while (dst[dsti] && dsti < size)
		dsti++;
	res = dsti + ft_strlen((char *)src);
	srci = 0;
	if (dsti < size)
	{
		while (dsti < size - 1 && src[srci])
		{
			dst[dsti] = src[srci];
			dsti++;
			srci++;
		}
		dst[dsti] = 0;
	}
	return (res);
}

char    *ft_strldup(const char *s, unsigned int len)
{
	unsigned int             i;
	char    *new;

	i = 0;
	while (s[i] && i < len)
		i++;
	new = malloc(i + 1);
	if (!new)
		return (nullptr);
	i = 0;
	while (s[i] && i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}