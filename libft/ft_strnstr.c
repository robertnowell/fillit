/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:15:51 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 18:21:47 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*s_big;
	char	*s_little;

	s_big = (char*)big;
	s_little = (char*)little;
	if (!(*s_little))
		return (s_big);
	if (!(*big))
		return (0);
	little_len = ft_strlen(s_little);
	while (len && len >= little_len && *s_big)
	{
		if (*s_big == *s_little)
		{
			if (ft_strncmp(s_big, s_little, little_len) == 0)
				return (s_big);
		}
		len--;
		s_big++;
	}
	return (0);
}
