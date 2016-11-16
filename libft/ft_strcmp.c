/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:20:01 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/21 20:20:02 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while ((*str1 == *str2) && *str1)
	{
		str1++;
		str2++;
	}
	return (*(unsigned const char*)str1 - *(unsigned const char*)str2);
}
