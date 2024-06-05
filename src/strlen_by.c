/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_by.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:07:39 by subson            #+#    #+#             */
/*   Updated: 2024/06/05 17:07:59 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlen_by(const char *start, const char *by)
{
	size_t	len;

	len = 0;
	while (start && start[len])
	{
		if (ft_strchr(by, start[len]))
			break ;
		else
			len++;
	}
	return (len);
}
