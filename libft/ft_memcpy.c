/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:42:15 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/22 16:42:17 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int			i;
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = (char *)str1;
	s2 = (const char *)str2;
	while (n > 0)
	{
		s1[i] = s2[i];
		n--;
		i++;
	}
	return (str1);
}
