/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:54 by subson            #+#    #+#             */
/*   Updated: 2024/06/05 16:27:24 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FILE_ERROR -3
# define FILE_END -2
# define NO_NL -1

typedef struct s_file
{
	int				fd;
	void			*str;
	size_t			len;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
ssize_t	get_next_line2(int fd, char **next_line);
char	*get_next_line_bonus(int fd);

size_t	gnl_strlen(const char *s);
ssize_t	gnl_strchr(char *s, char c, size_t len);
char	*gnl_substr(char const *s, ssize_t start, ssize_t end);
t_file	*find_cur_file(t_file **file, int fd);
int		remove_file(t_file **file_p, int fd);

#endif