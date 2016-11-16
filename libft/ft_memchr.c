/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:12:25 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/29 01:22:15 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*s1;

	s1 = str;
	while (n > 0)
	{
		if (*s1 == c || (unsigned char)*s1 == (unsigned char)c)
			return ((void*)s1);
		s1++;
		n--;
	}
	return (0);
}
