/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:18:48 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/21 13:18:55 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	t;

	i = ft_strlen(dest);
	t = 0;
	while (src[t] != '\0')
	{
		dest[i] = src[t];
		i++;
		t++;
	}
	dest[i] = '\0';
	return (dest);
}
