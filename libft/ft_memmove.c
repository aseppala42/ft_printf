/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:51:03 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/03 14:59:27 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	if (len == 0 || src == 0)
		return (dst);
	ft_memrcpy(dst + 1, src + 1, --len);
	*(unsigned char *)dst = *(unsigned char *)src;
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0 || src == 0 || \
		(unsigned char *)dst == (unsigned char *)src)
		return (dst);
	if ((unsigned char *)src < (unsigned char *)dst)
		return (ft_memrcpy(dst, src, len));
	else
		return (ft_memcpy(dst, src, len));
}
