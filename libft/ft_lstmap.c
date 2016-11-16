/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:03:42 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/28 15:24:58 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	addend(t_list **list, t_list *node)
{
	t_list	*point;

	point = *list;
	if (point)
	{
		while (point->next)
			point = point->next;
		point->next = node;
	}
	else
		*list = node;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*node;
	t_list	*temp;

	new = 0;
	while (lst->next)
	{
		temp = f(lst);
		node = ft_lstnew(temp->content, temp->content_size);
		if (!node)
			return (0);
		addend(&new, node);
		lst = lst->next;
	}
	temp = f(lst);
	node = ft_lstnew(temp->content, temp->content_size);
	if (!node)
		return (0);
	addend(&new, node);
	return (new);
}
