/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:36:09 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/03 14:24:25 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, \
		int c, size_t n)
{
	if (n == 0 || src == 0)
		return (0);
	*(unsigned char *)dst = *(unsigned char *)src;
	if (*(unsigned char *)dst == (unsigned char)c)
		return (++dst);
	return (ft_memccpy(++dst, ++src, c, --n));
}
