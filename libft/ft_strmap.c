/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:49:45 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/02 22:00:53 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mapiter(char *s, char (*f)(char))
{
	if (s == 0 || *s == 0)
		return ;
	*s = f(*s);
	ft_mapiter(++s, f);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;

	if (s == 0)
		return (0);
	if (!(map = ft_strdup(s)))
		return (0);
	ft_mapiter(map, f);
	return (map);
}
