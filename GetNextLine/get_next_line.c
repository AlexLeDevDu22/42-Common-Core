/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarin <agarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:54:39 by agarin            #+#    #+#             */
/*   Updated: 2026/11/20 17:00:35 by agarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// static char    *empty_str(size_t size)
// {
// 	char    *res;
// 	size_t i;

// 	res = malloc(size);
// 	if (!res)
// 		return (nullptr);
// 	i = 0;
// 	while (i < size)
// 	{
// 		res[i] = 0;
// 		i++;
// 	}
// 	return (res);
// }

static char *add_to_rest(char *actual_rest, char *content)
{
	char *new_rest;
	unsigned int size;

	size = ft_strlen(actual_rest) + ft_strlen(content);
	new_rest = malloc(size + 1);
	if (!new_rest)
		return (NULL);
	ft_strlcpy(new_rest, actual_rest, ft_strlen(actual_rest) + 1);
	free(actual_rest);
	ft_strlcat(new_rest, content, size + 1);
	new_rest[size] = 0;
	return (new_rest);
}


// static char *create_line(char *rest, char *content, char* end)
// {
// 	char *result;
// 	int len;

// 	len = ft_strlen(rest) + end - content + 1;
// 	result = malloc(len + 1);
// 	if (!result)
// 		return (NULL);
// 	ft_strcpy(result, (char *)rest);
// 	ft_strlcat(result, content, len + 1);
// 	result[len] = 0;
// 	return (result);
// }

// char	*get_next_line(int fd)
// {
// 	static char *rest = NULL;
// 	char *content;
// 	int		bytes_read;
// 	char *line;
// 	char *end;

// 	if (!rest)
// 		rest = empty_str(1);
// 	if (fd < 0 || BUFFER_SIZE <= 0)
//     	return (NULL);
// 	content = empty_str(BUFFER_SIZE);
// 	if (!content)
// 		return (NULL);
// 	bytes_read = read(fd, content, BUFFER_SIZE);
// 	if (bytes_read <= 0 && (!rest || !(*rest)))
// 	{
// 		free(rest);
// 		free(content);
// 		return (NULL);
// 	}
// 	line = NULL;
// 	end = ft_strchr(content, '\n');
// 	if (!end && bytes_read < BUFFER_SIZE)
// 		end  = ft_strchr(content, 0);
// 	if (end)
// 	{
// 		line = create_line(rest, content, end);
// 		free(rest);
// 		if (!line)
// 			return (NULL);
// 		if (*end == '\n')
// 			rest = ft_strdup(end + 1);
// 		else
// 			rest = empty_str(1);
// 		free(content);
// 		return (line);
// 	}
// 	rest = add_to_rest(rest, content);
// 	free(content);
// 	if (!rest)
// 		return (NULL);
// 	return (get_next_line(fd));
// }

// static char *split_rest(char **rest)
// {
// 	char *mid;
// 	unsigned int mid_size;
// 	char *tmp_rest;
// 	char *line;
	
// 	mid = ft_strchr(*rest, '\n');
// 	if (!mid)
// 		mid = ft_strchr(*rest, 0);
// 	if (!*mid && mid == *rest)
// 		return (NULL);
// 	mid_size = mid - *rest + 1;
// 	line = malloc(mid_size + 1);
// 	if (!line)
// 		return (NULL);
// 	ft_strlcpy(line, *rest, mid_size + 1);
// 	if (*mid)
// 	{
// 		tmp_rest = malloc(ft_strlen(mid + 1) + 1);
// 		if (!tmp_rest)
// 			return (NULL);
// 		ft_strlcpy(tmp_rest, mid + 1, ft_strlen(*rest) - mid_size + 1);
// 		free(*rest);
// 		*rest = tmp_rest;
// 	}
// 	return (line);
// }



#include <stdio.h>




static char *split_rest(char **rest)
{
	char *line;
	char *tmp_rest;
	char *nl;
	
	if (!(**rest))
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	nl = ft_strchr(*rest, '\n');
	if (nl)
	{
		line = ft_strldup(*rest, nl - *rest + 1);
		if (nl[1])
			tmp_rest = ft_strldup(nl + 1, *rest + ft_strlen(*rest) - nl - 1);
		else
			tmp_rest = NULL;
		free(*rest);
		*rest = tmp_rest;
	} else
	{
		line = ft_strldup(*rest, -1);
		free(*rest);
		*rest = NULL;
	}
	return (line);
}











char *get_next_line(int fd)
{
	static char *rest = NULL;
	char        *content;
	int         bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
	{
		rest = malloc(1);
		if (!rest)
			return (NULL);
		rest[0] = 0;
	}
	content = malloc(BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(rest, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, content, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			content[bytes_read] = '\0';
			rest = add_to_rest(rest, content);
		}
	}
	free(content);
	if (bytes_read < 0)
		return (NULL);
	return (split_rest(&rest));
}

#include <fcntl.h>
int main()
{
	int fd  = open("test.txt", O_RDONLY);
	char *line1 = get_next_line(fd);
	printf(">>>  %s", line1);
	char *line2 = get_next_line(fd);
	printf(">>>  %s", line2);
	if (line1)
		free(line1);
	if (line2)
		free(line2);
	return (0);
}