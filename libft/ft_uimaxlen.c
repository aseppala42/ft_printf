/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:19:52 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/18 18:20:02 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uimaxlen(uintmax_t n, unsigned int base)
{
	if (base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (n > base - 1)
		return (1 + ft_uimaxlen(n / base, base));
	return (1);
}
