/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 23:41:07 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/27 16:22:09 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	n_len(size_t *len, int *negetiv, long *n)
{
	long	temp_n;

	if (*n < 0)
	{
		*negetiv = 1;
		*n *= -1;
	}
	else
		*negetiv = 0;
	temp_n = *n;
	*len = (*n == 0) ? 1 : 0;
	while (temp_n > 0)
	{
		(*len)++;
		temp_n /= 10;
	}
}

char		*ft_itoa(int n)
{
	size_t	len;
	int		negetiv;
	char	*new;
	long	num;

	num = n;
	n_len(&len, &negetiv, &num);
	new = (char*)malloc(sizeof(char) * (len + negetiv + 1));
	if (!new)
		return (0);
	len += negetiv;
	new[len] = '\0';
	len--;
	if (num == 0)
		new[len] = '0';
	while (num > 0)
	{
		new[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (negetiv == 1)
		new[0] = '-';
	return (new);
}
