/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:07:03 by subson            #+#    #+#             */
/*   Updated: 2024/06/05 17:07:21 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchrs(const char *str, const char *pattern)
{
	size_t	i;

	i = 0;
	if (!str || !pattern)
		return ((void *)0);
	while (str[i])
	{
		if (ft_strchr(pattern, str[i]))
			return ((char *)&str[i]);
		i++;
	}
	return ((void *)0);
}
