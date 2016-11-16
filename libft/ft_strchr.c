/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:58:34 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/21 15:58:35 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (*str == c)
		return ((char *)str);
	while (*str++)
	{
		if (*str == c)
			return ((char *)str);
	}
	return (0);
}
