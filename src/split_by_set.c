/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:39:53 by subson            #+#    #+#             */
/*   Updated: 2024/06/05 17:09:33 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	get_cnt(char const *s, char *set);
char static	*split(char const **str, char *set);
void static	free_all(char **strs, int n);

char	**split_by_set(char const *s, char *set)
{
	int		cnt;
	char	**strs;
	int		i;

	cnt = get_cnt(s, set);
	strs = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (!strs)
		return ((void *)0);
	i = 0;
	while (i < cnt)
	{
		strs[i] = split(&s, set);
		if (!strs[i])
		{
			free_all(strs, i);
			return ((void *)0);
		}
		i++;
	}
	return (strs);
}

int	static	get_cnt(char const *s, char *set)
{
	int		cnt;
	int		i;
	char	*current;
	char	*next;

	cnt = 0;
	if (!s)
		return (0);
	i = 0;
	current = ft_strchr(set, s[i]);
	while (s[i])
	{
		next = ft_strchr(set, s[i + 1]);
		if (!current && (next || s[i + 1] == '\0'))
			cnt++;
		current = next;
		i++;
	}
	return (cnt);
}

char static	*split(char const **str, char *set)
{
	int		each_len;
	char	*next_p;
	char	*splited;

	while (**str)
	{
		next_p = strchrs(*str, set);
		if (next_p)
			each_len = next_p - *str;
		else
			each_len = ft_strlen(*str);
		if (each_len)
		{
			splited = ft_substr(*str, 0, each_len);
			*str += (each_len + 1);
			return (splited);
		}
		else
			(*str)++;
	}
	return ((void *)0);
}

void static	free_all(char **strs, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		free(strs[i++]);
	free(strs);
}
