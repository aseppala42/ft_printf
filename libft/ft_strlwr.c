/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:58:17 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 12:58:21 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlwr(char *str)
{
	if (!str || *str == 0)
		return (str);
	if (ft_isupper(*str))
		*str += 32;
	ft_strlwr(str + 1);
	return (str);
}
