/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:15:52 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/02 15:40:02 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0 && s2 != 0)
		return (ft_strdup(s2));
	if (s1 != 0 && s2 == 0)
		return (ft_strdup(s1));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	ft_strcpy(str, s1);
	return (ft_strcat(str, s2));
}
