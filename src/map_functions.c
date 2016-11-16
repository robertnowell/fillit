/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:38:42 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 16:38:45 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tetris.h"

char	**create_map(size_t map_size)
{
	char	**map;
	size_t	j;

	j = 0;
	map = (char**)malloc(sizeof(char*) * map_size);
	if (!map)
		return (0);
	while (j < map_size)
	{
		map[j] = (char*)malloc(sizeof(char) * map_size);
		if (!map[j])
			return (0);
		ft_memset(map[j], '.', map_size);
		j++;
	}
	return (map);
}

bool	update_next_point(t_map *settings, char **map)
{
	int	x;
	int	y;
	int	size;

	x = settings->x_point;
	y = settings->y_point;
	size = settings->map_size - 1;
	if (x == size && y == size)
		return (0);
	if (x != size)
		x++;
	else if (x == size)
	{
		x = 0;
		y++;
	}
	settings->x_point = x;
	settings->y_point = y;
	if (map[y][x] != '.')
		return (update_next_point(settings, map));
	return (1);
}

void	delete_last_tetriminos(char **map, t_map *settings, int location, int y)
{
	int		x;
	int		count;
	char	type;

	count = 0;
	type = 'A' + location;
	while (y < settings->map_size)
	{
		x = 0;
		while (x < settings->map_size)
		{
			if (map[y][x] == type)
			{
				map[y][x] = '.';
				if (count == 0)
				{
					settings->x_point = x;
					settings->y_point = y;
				}
				count++;
			}
			x++;
		}
		y++;
	}
}

void	print_map(char **map, t_map *settings)
{
	int	x;
	int	y;
	int	size;

	y = 0;
	size = settings->map_size;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
