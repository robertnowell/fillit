/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:56:11 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/21 12:56:13 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	while (i < n)
	{
		dest[i] = src[i];
		if (s_len < i)
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
