/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:56:01 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/29 11:10:18 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = str1;
	s2 = str2;
	if (!(s2 <= s1 && s2 + n >= s1))
		return (ft_memcpy(str1, str2, n));
	n--;
	while (n > 0)
	{
		s1[n] = s2[n];
		n--;
	}
	*s1 = *s2;
	return (str1);
}
