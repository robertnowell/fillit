/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:15:50 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 14:08:57 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = dst;
	s2 = src;
	while (n > 0)
	{
		*s1 = *s2;
		if (*s1 == (unsigned char)c)
			return (++s1);
		n--;
		s2++;
		s1++;
	}
	return (s1 = 0);
}
