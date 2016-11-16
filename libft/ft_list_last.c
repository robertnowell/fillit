/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:00:19 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/05 11:01:05 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *temp;

	if (begin_list == 0)
		return (0);
	temp = begin_list;
	while (temp->next != 0)
		temp = temp->next;
	return (temp);
}
