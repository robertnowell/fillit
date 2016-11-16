/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:39:11 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 16:39:13 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int	main(int argc, char *argv[])
{
	t_map		*settings;
	char		**map;
	char		***array;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	settings = init_settings();
	array = get_data(argv[1], settings);
	map = create_map(settings->map_size);
	if (!map || !settings || !array)
		return (0);
	while (1)
	{
		if (solver(map, settings, array, 0))
			break ;
		settings->map_size += 1;
		free(map);
		if (!(map = create_map(settings->map_size)))
			return (0);
	}
	print_map(map, settings);
	return (0);
}
