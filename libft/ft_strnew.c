/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:34:43 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 14:12:38 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	ft_bzero(arr, size + 1);
	return (arr);
}
