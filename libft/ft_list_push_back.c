/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:46:21 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/05 11:14:14 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data, size_t content_size)
{
	t_list *new;
	t_list *temp;

	new = ft_lstnew(data, content_size);
	if (*begin_list == 0)
		*begin_list = new;
	else
	{
		temp = *begin_list;
		if (temp->next == 0)
			temp->next = new;
		else
		{
			while (temp->next != 0)
				temp = temp->next;
			temp->next = new;
		}
	}
}
