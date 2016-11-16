/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:39:37 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 16:39:39 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tetris.h"

void	find_first(char **array, t_map *settings)
{
	X_TERMINO = 0;
	Y_TERMINO = 0;
	while (Y_TERMINO < 4)
	{
		X_TERMINO = 0;
		while (X_TERMINO < 4)
		{
			if (array[Y_TERMINO][X_TERMINO] == '#')
				return ;
			X_TERMINO++;
		}
		Y_TERMINO++;
	}
}

bool	fit_possibility(char **map, t_map *settings,
	char ***array, int location)
{
	int	count;

	Y_VIRTUAL = settings->y_point;
	X_VIRTUAL = settings->x_point;
	if (X_VIRTUAL == M_SIZE - 1 && Y_VIRTUAL == M_SIZE - 1)
		return (0);
	count = 0;
	find_first(array[location], settings);
	while (1)
	{
		if ((X_VIRTUAL == M_SIZE) ||
			(Y_VIRTUAL == M_SIZE || Y_TERMINO == 4) ||
			(map[Y_VIRTUAL][X_VIRTUAL] != '.' && T_BOX == '#'))
			return (0);
		if (map[Y_VIRTUAL][X_VIRTUAL] == '.' && T_BOX == '#')
			count++;
		if (count == 4)
			return (1);
		possibility_steps(settings);
	}
}

void	put_tetriminos(char **map, t_map *settings, char ***array, int location)
{
	int		count;
	char	type;

	count = 0;
	type = 'A' + location;
	Y_VIRTUAL = settings->y_point;
	X_VIRTUAL = settings->x_point;
	find_first(array[location], settings);
	while (1)
	{
		if (map[Y_VIRTUAL][X_VIRTUAL] == '.' && T_BOX == '#')
		{
			count++;
			map[Y_VIRTUAL][X_VIRTUAL] = type;
		}
		if (count == 4)
			return ;
		possibility_steps(settings);
	}
}

bool	solver(char **map, t_map *settings, char ***array, int location)
{
	settings->x_point = 0;
	settings->y_point = 0;
	while (1)
	{
		if (fit_possibility(map, settings, array, location))
		{
			put_tetriminos(map, settings, array, location);
			if (location == settings->pieces_count - 1)
				return (1);
			X_POINT = -1;
			Y_POINT = 0;
			update_next_point(settings, map);
			location++;
		}
		else
		{
			if (update_next_point(settings, map))
				continue ;
			else if (!location)
				return (0);
			delete_last_tetriminos(map, settings, location - 1, 0);
			update_next_point(settings, map);
			location--;
		}
	}
}
