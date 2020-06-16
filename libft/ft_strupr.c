/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:58:31 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 12:58:34 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupr(char *str)
{
	if (!str || *str == 0)
		return (str);
	if (ft_islower(*str))
		*str -= 32;
	ft_strupr(str + 1);
	return (str);
}
