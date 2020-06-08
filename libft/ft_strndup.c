/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:35:37 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/01 21:40:25 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;

	if (!(cpy = ft_strnew(n)))
		return (0);
	ft_strncpy(cpy, s1, n);
	cpy[n] = 0;
	return (cpy);
}
