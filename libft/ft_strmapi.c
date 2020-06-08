/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:41:30 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/02 22:05:34 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mapiteri(char *s, char (*f)(unsigned int, char))
{
	int		i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		s[i] = f(i, s[i]);
		i++;
	}
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;

	if (s == 0)
		return (0);
	if (!(map = ft_strdup(s)))
		return (0);
	ft_mapiteri(map, f);
	return (map);
}
