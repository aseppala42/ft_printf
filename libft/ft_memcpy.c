/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:59:18 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/02 20:46:00 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	if (n == 0 || src == 0)
		return (dst);
	*(unsigned char *)dst = *(unsigned char *)src;
	ft_memcpy(dst + 1, ++src, --n);
	return (dst);
}
