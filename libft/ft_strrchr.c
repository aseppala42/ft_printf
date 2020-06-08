/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:02:11 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/01 19:38:14 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	if (*s == (char)c)
		if (*s == 0 || ft_strrchr(s + 1, c) == 0)
			return ((char *)s);
	if (*s == 0)
		return (0);
	return (ft_strrchr(++s, c));
}