/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:54:00 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 17:54:08 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tetris.h"

void	possibility_steps(t_map *settings)
{
	if ((X_VIRTUAL == M_SIZE - 1 && Y_VIRTUAL < M_SIZE - 1) ||
		(X_TERMINO == 3 && Y_TERMINO < 3))
	{
		Y_VIRTUAL++;
		X_VIRTUAL -= X_TERMINO;
		Y_TERMINO++;
		X_TERMINO = 0;
		if (X_VIRTUAL < 0)
		{
			X_TERMINO += (X_VIRTUAL * -1);
			X_VIRTUAL = 0;
		}
	}
	else
	{
		X_TERMINO++;
		X_VIRTUAL++;
	}
}

t_map	*init_settings(void)
{
	t_map	*settings;

	if (!(settings = (t_map*)malloc(sizeof(t_map))))
		return (0);
	settings->x_point = 0;
	settings->y_point = 0;
	settings->map_size = 2;
	settings->x_termino = 0;
	settings->y_termino = 0;
	return (settings);
}

char	***get_data(char *str, t_map *settings)
{
	char	*s;
	char	*pieces;
	char	***array;

	pieces = (char *)malloc(sizeof(char) * 27);
	if (!(s = ft_read(str)))
		return (0);
	if (ft_s_error(s, 0, 0, 0))
	{
		ft_putendl("error");
		return (0);
	}
	array = ft_pieces_array(s);
	ft_fill_array(array, s, 0, 0);
	if (!(*(pieces = ft_analyze(s))))
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_find(pieces, 'z'))
		return (0);
	settings->pieces_count = ft_count_pieces(s);
	return (array);
}
