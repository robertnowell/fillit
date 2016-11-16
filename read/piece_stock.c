/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 20:36:52 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 20:36:53 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tetris.h"

char	stock_one(char *s, int i)
{
	if (s[i + 1] == '#' && s[i + 4] == '#' && s[i + 5] == '#')
		return ('a');
	if (s[i + 5] == '#' && s[i + 6] == '#' && s[i + 11] == '#')
		return ('b');
	if (s[i + 1] == '#' && s[i + 6] == '#' && s[i + 7] == '#')
		return ('c');
	if (s[i + 4] == '#' && s[i + 5] == '#' && s[i + 9] == '#')
		return ('d');
	if (s[i + 4] == '#' && s[i + 5] == '#' && s[i + 6] == '#')
		return ('e');
	if (s[i + 4] == '#' && s[i + 5] == '#' && s[i + 10] == '#')
		return ('f');
	return ('z');
}

char	stock_two(char *s, int i)
{
	if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 6] == '#')
		return ('g');
	if (s[i + 5] == '#' && s[i + 6] == '#' && s[i + 10] == '#')
		return ('h');
	if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 15] == '#')
		return ('i');
	if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 3] == '#')
		return ('j');
	if (s[i + 1] == '#' && s[i + 5] == '#' && s[i + 6] == '#')
		return ('k');
	if (s[i + 1] == '#' && s[i + 5] == '#' && s[i + 10] == '#')
		return ('l');
	return ('z');
}

char	stock_three(char *s, int i)
{
	if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 7] == '#')
		return ('m');
	if (s[i + 5] == '#' && s[i + 9] == '#' && s[i + 10] == '#')
		return ('n');
	if (s[i + 5] == '#' && s[i + 6] == '#' && s[i + 7] == '#')
		return ('o');
	if (s[i + 1] == '#' && s[i + 6] == '#' && s[i + 11] == '#')
		return ('p');
	if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 5] == '#')
		return ('q');
	if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 11] == '#')
		return ('r');
	if (s[i + 3] == '#' && s[i + 4] == '#' && s[i + 5] == '#')
		return ('s');
	return ('z');
}

char	ft_piece(char *s, int i)
{
	char	c;

	c = stock_one(s, i);
	if (c != 'z')
		return (c);
	c = stock_two(s, i);
	if (c != 'z')
		return (c);
	c = stock_three(s, i);
	if (c != 'z')
		return (c);
	ft_putendl("error");
	return ('z');
}
