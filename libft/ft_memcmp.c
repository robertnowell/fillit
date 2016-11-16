/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:21:10 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/22 18:21:11 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const char	*s1;
	const char	*s2;

	s1 = str1;
	s2 = str2;
	if (!n)
		return (0);
	while ((*s1 == *s2) && (n > 1))
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned const char*)s1 - *(unsigned const char*)s2);
}
