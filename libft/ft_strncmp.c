/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:02:05 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/22 11:02:07 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*str1 == *str2) && (n > 1) && (*str1))
	{
		str1++;
		str2++;
		n--;
	}
	return (*(unsigned const char*)str1 - *(unsigned const char*)str2);
}
