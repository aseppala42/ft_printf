/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:27:20 by aseppala          #+#    #+#             */
/*   Updated: 2019/10/22 11:01:57 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_atoi(const char *str, int res)
{
	if (!ft_isdigit(*str))
		return (res);
	return (ft_recursive_atoi(str + 1, res * 10 + (*str - '0')));
}

int			ft_atoi(const char *str)
{
	if (ft_isspace(*str))
		return (ft_atoi(++str));
	if (*str == '-')
		return (-ft_recursive_atoi(++str, 0));
	if (*str == '+')
		return (ft_recursive_atoi(++str, 0));
	if (ft_isdigit(*str))
		return (ft_recursive_atoi(str, 0));
	return (0);
}
