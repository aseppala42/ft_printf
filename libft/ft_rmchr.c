/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:46:57 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/16 12:54:19 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**char	*ft_rmchr(char *src, char c)
**{
**	char	*dst;
**	char	tmp;
**
**	dst = ft_strnew(ft_strlen(str));
**	tmp = dst;
**	while (*src != 0)
**	{
**		if (*src != c)
**			*tmp++ = *src;
**		src++;
**	}
**	return (dst);
**}
**
**char	*ft_rmchr(char *str, char c)
**{
**	char	tmp;
**
**	if (!str || *str == 0 || !(tmp = ft_strchr(str, c)))
**		return (str);
**	ft_strcpy(tmp, tmp  + 1);
**	ft_rmchr(tmp, c);
**	return (str);
**}
**
**
** add:
** str = ft_strdup(str);
** before while in the below function
*/

char	*ft_rmchr(char *str, char c)
{
	char	*tmp;

	while ((tmp = ft_strchr(str, c)))
		ft_strcpy(tmp, tmp + 1);
	return (str);
}
