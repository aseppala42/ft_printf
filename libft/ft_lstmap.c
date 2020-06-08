/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:26:42 by aseppala          #+#    #+#             */
/*   Updated: 2019/10/31 17:25:31 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*prev_lst;

	if (lst->next == 0)
		return (0);
	prev_lst = ft_lstmap(lst->next, f);
	ft_lstadd(&prev_lst, f(lst));
	return (prev_lst);
}
