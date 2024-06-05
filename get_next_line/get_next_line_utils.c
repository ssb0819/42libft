/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:28 by subson            #+#    #+#             */
/*   Updated: 2024/06/05 16:06:01 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

ssize_t	gnl_strchr(char *s, char c, size_t len)
{
	ssize_t	i;
	ssize_t	size;

	i = 0;
	size = len;
	if (!s)
		return (-1);
	while (i < size)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_substr(char const *s, ssize_t start, ssize_t end)
{
	char	*res;
	ssize_t	len;
	ssize_t	i;

	if (!s)
		return ((void *)0);
	len = end - start;
	if (len <= 0)
		return ((void *)0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_file	*find_cur_file(t_file **file_p, int fd)
{
	t_file	*new_file;

	if (*file_p)
	{
		while (*file_p)
		{
			if ((*file_p)->fd == fd)
				return (*file_p);
			file_p = &((*file_p)->next);
		}
	}
	new_file = malloc(sizeof(t_file));
	if (!new_file)
		return ((void *)0);
	new_file->fd = fd;
	new_file->len = 0;
	new_file->str = (void *)0;
	new_file->next = (void *)0;
	*file_p = new_file;
	return (new_file);
}

int	remove_file(t_file **next_p, int fd)
{
	t_file	*cur;

	if (!next_p)
		return (0);
	cur = *next_p;
	while (cur)
	{
		if (cur->fd == fd)
		{
			*next_p = cur->next;
			free(cur->str);
			free(cur);
			return (fd);
		}
		next_p = &(cur->next);
		cur = cur->next;
	}
	return (0);
}
