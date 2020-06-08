/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:50:06 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/03 14:54:02 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(dst);
	if (src == 0)
		return (len);
	if (dstsize == 0 || len > dstsize)
		return (dstsize + ft_strlen(src));
	if (dstsize > len)
		ft_strlcpy(dst + len, src, dstsize - len);
	return (len + ft_strlen(src));
}
