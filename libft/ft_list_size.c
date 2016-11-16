/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:43:48 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/05 10:45:22 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*temp;

	count = 0;
	if (begin_list == 0)
		return (count);
	else
	{
		temp = begin_list;
		while (temp->next != 0)
		{
			count++;
			temp = temp->next;
		}
		return (count + 1);
	}
}
