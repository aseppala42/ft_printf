/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:22:09 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/03 13:35:07 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_and_add(char const *s, char c, \
		char **array, size_t count)
{
	if (*s == 0)
		return (array);
	if (*s == c)
		return (ft_split_and_add(++s, c, array, count));
	if (!(array[count] = ft_strndup(s, ft_strclen(s, c))))
		return (0);
	return (ft_split_and_add(s + ft_strclen(s, c), c, array, ++count));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (s == 0)
		return (0);
	if (!(array = ft_memalloc(sizeof(char *) * (ft_strcount(s, c) + 1))))
		return (0);
	return (ft_split_and_add(s, c, array, 0));
}
