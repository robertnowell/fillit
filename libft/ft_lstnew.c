/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 09:30:35 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/28 12:13:30 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = 0;
	if ((void*)content != 0)
	{
		new->content = malloc(content_size);
		ft_memcpy(new->content, (void*)content, content_size);
	}
	new->content_size = (content != 0) ? content_size : 0;
	new->next = 0;
	return (new);
}
