/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:06:58 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/05 11:08:21 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab)
{
	int i;
	int count;
	int j;

	i = 0;
	j = 0;
	count = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('0');
}
