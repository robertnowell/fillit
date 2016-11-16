/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:17:53 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/22 11:18:03 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					minus;

	res = 0;
	minus = 0;
	while (ft_strncmp(str, " ", 1) == 0 || ft_strncmp(str, "\r", 1) == 0 ||
		ft_strncmp(str, "\n", 1) == 0 || ft_strncmp(str, "\t", 1) == 0 ||
		ft_strncmp(str, "\v", 1) == 0 || ft_strncmp(str, "\f", 1) == 0)
		str++;
	if (*str == '-')
		minus = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str > 57 || *str < 48)
			break ;
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (minus > 0 ? (-res) : (res));
}
