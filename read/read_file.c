/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 20:14:47 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/07 20:14:49 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tetris.h"

char	*ft_read(char *file)
{
	char	buffer[BUF_SIZE];
	int		file_desc;
	int		i;
	int		ret;
	char	*s;

	s = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	file_desc = 0;
	i = 0;
	file_desc = open(file, O_RDONLY);
	if (file_desc == -1)
	{
		ft_putstr("file error\n");
		return (0);
	}
	while ((ret = read(file_desc, buffer, 1)))
	{
		s[i] = buffer[0];
		i++;
	}
	s[i] = '\0';
	close(file_desc);
	return (s);
}

char	*ft_analyze(char *s)
{
	char	*pieces;
	int		count;
	int		i;

	i = 0;
	count = 0;
	pieces = (char *)malloc(sizeof(char) * 27);
	while (s[i])
	{
		if (s[i] == '#')
		{
			pieces[count] = ft_piece(s, i);
			count++;
			while (s[i])
			{
				if (s[i] == '\n' && s[i + 1] == '\n')
					break ;
				i++;
			}
		}
		i++;
	}
	return (pieces);
}

int		ft_s_error(char *s, int i, int dotcount, int hashcount)
{
	int	nlcount;

	if (s[i] != '.' && s[i] != '#')
		return (1);
	while (s[i])
	{
		dotcount = 0;
		hashcount = 0;
		nlcount = 0;
		while (!(s[i] == '\n' && s[i + 1] == '\n'))
		{
			if (s[i] == '\n' && s[i + 1] == '\0')
				break ;
			dotcount = (s[i] == '.') ? dotcount + 1 : dotcount;
			hashcount = (s[i] == '#') ? hashcount + 1 : hashcount;
			nlcount = (s[i] == '\n') ? nlcount + 1 : nlcount;
			if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
				return (1);
			i++;
		}
		if (dotcount != 12 || hashcount != 4 || nlcount != 3)
			return (1);
		i = (s[i] && s[i + 1] && s[i + 2]) ? i + 2 : i + 1;
	}
	return (0);
}
