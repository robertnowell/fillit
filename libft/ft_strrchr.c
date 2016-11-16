/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:43:39 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/21 16:43:41 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*temp;

	temp = 0;
	if (*str == c)
		temp = str;
	while (*str++)
	{
		if (*str == c)
			temp = str;
	}
	str = temp;
	return ((char *)str);
}
