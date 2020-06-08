/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:31:10 by aseppala          #+#    #+#             */
/*   Updated: 2019/10/31 18:26:30 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (0);
	if (content == 0)
	{
		list->content = 0;
		list->content_size = 0;
	}
	else
	{
		list->content = \
		ft_memcpy(ft_memalloc(content_size), content, content_size);
		list->content_size = content_size;
	}
	list->next = 0;
	return (list);
}
