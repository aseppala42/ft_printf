/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:01:34 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 13:01:37 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	if (*s == 0 || *charset == 0)
		return (0);
	if (ft_strchr(charset, *s))
		return ((char *)s);
	return (ft_strpbrk(++s, charset));
}
