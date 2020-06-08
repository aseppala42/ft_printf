/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:47:07 by aseppala          #+#    #+#             */
/*   Updated: 2019/12/06 14:56:50 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	next[FD_MAX][BUFF_SIZE + 1];
	char		buf[BUFF_SIZE];
	int			ret;

	if (line == 0 || fd < 0 || fd > FD_MAX)
		return (-1);
	*line = 0;
	while (1)
	{
		*line = ft_joindel(*line, ft_strndup(next[fd],
					ft_strclen(next[fd], '\n')));
		if (ft_strchr(next[fd], '\n'))
		{
			ft_strcpy(next[fd], next[fd] + ft_strclen(next[fd], '\n') + 1);
			return (1);
		}
		ft_bzero(next[fd], BUFF_SIZE);
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (!ret)
			return (!!**line);
		ft_strncpy(next[fd], buf, ret);
	}
}
