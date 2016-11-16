/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 20:36:18 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 20:36:21 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tetris.h"

int		ft_find(char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}

int		ft_count_pieces(char *s)
{
	int	number_of_pieces;
	int	i;

	i = 0;
	number_of_pieces = 0;
	while (*s)
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == 0))
			number_of_pieces++;
		s++;
	}
	return (number_of_pieces);
}

char	***ft_pieces_array(char *s)
{
	char	***pieces;
	int		pieces_count;
	int		piece;
	int		row;

	piece = 0;
	pieces_count = ft_count_pieces(s);
	if (!(pieces = (char ***)malloc((pieces_count + 1) * sizeof(char **))))
		return (NULL);
	pieces[pieces_count] = 0;
	while (piece < pieces_count)
	{
		if (!(pieces[piece] = (char **)malloc(4 * sizeof(char *))))
			return (NULL);
		row = 0;
		while (row < 4)
		{
			if (!(pieces[piece][row] = (char *)malloc(4 * sizeof(char))))
				return (NULL);
			row++;
		}
		piece++;
	}
	return (pieces);
}

void	ft_fill_array(char ***pieces, char *s, int i, int piece)
{
	int	pieces_count;
	int	row;
	int	column;

	pieces_count = ft_count_pieces(s);
	while (piece < pieces_count)
	{
		row = 0;
		while (row < 4)
		{
			column = 0;
			while (column < 4)
			{
				if (!(s[i] == '\n'))
				{
					pieces[piece][row][column] = s[i];
					column++;
				}
				i++;
			}
			i++;
			row++;
		}
		piece++;
	}
}
