/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:46:06 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/28 15:26:09 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*point;

	point = *alst;
	while (point->next != 0)
	{
		point = point->next;
		ft_lstdelone(&(*alst), del);
		*alst = point;
	}
	ft_lstdelone(&(*alst), del);
	*alst = 0;
}
