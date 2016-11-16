/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:33:44 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/02 15:53:09 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H
# define X_VIRTUAL settings->x_virtual
# define Y_VIRTUAL settings->y_virtual
# define X_POINT settings->x_point
# define Y_POINT settings->y_point
# define X_TERMINO settings->x_termino
# define Y_TERMINO settings->y_termino
# define M_SIZE settings->map_size
# define T_BOX	array[location][settings->y_termino][settings->x_termino]

# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_settings
{
	int	x_point;
	int	y_point;
	int	map_size;
	int	pieces_count;
	int	x_termino;
	int	y_termino;
	int	x_virtual;
	int	y_virtual;

}				t_map;

void			print_map(char **map, t_map *settings);
bool			solver(char **map, t_map *settings, char ***array,
				int location);
void			put_tetriminos(char **map, t_map *settings,
				char ***array, int location);
bool			fit_possibility (char **map, t_map *settings,
				char ***array, int location);
void			find_first(char **array, t_map *settings);
void			delete_last_tetriminos(char **map, t_map *settings,
				int location, int y);
bool			update_next_point(t_map *settings, char **map);
char			**create_map(size_t map_size);
void			ft_fill_array(char ***pieces, char *s, int i, int piece);
char			***ft_pieces_array(char *s);
int				ft_count_pieces(char *s);
int				ft_find(char *s, char c);
int				ft_s_error(char *s, int i, int dotcount, int hashcount);
char			*ft_analyze(char *s);
char			ft_piece(char *s, int i);
char			*ft_read(char *file);
void			possibility_steps(t_map *settings);
t_map			*init_settings(void);
char			***get_data(char *str, t_map *settings);
#endif
