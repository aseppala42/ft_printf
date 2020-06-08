/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:25:58 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/03 13:42:53 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	if (src == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	*dst = *src;
	if (*src != 0 && dstsize != 1)
		ft_strlcpy(++dst, src + 1, --dstsize);
	if (dstsize == 1)
		*dst = 0;
	return (ft_strlen(src));
}
