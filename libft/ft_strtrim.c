/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 22:51:04 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 16:19:21 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_points(int *start, int *end, char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	*start = i;
	if (s[i] != '\0')
	{
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		*end = i + 1;
	}
	else
	{
		*start = 0;
		*end = 0;
	}
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		t;
	int		start;
	int		end;
	char	*news;

	i = 0;
	t = 0;
	set_points(&start, &end, s);
	news = (char*)malloc(sizeof(char) * (end - start + 1));
	if (!news)
		return (0);
	i = start;
	while (i < end)
	{
		news[t] = s[i];
		i++;
		t++;
	}
	news[t] = '\0';
	return (news);
}
