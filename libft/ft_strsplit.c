/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 23:30:29 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 18:09:11 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		give_point(char const *s, char c, int *i)
{
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	if (s[*i] == '\0')
		*i = -1;
	return (*i);
}

static size_t	words_count(char const *s, char c)
{
	size_t	count;
	int		status;

	count = 0;
	status = 0;
	while (*s)
	{
		if (*s == c)
			status = 0;
		if (*s != c && status == 0)
		{
			count++;
			status = 1;
		}
		s++;
	}
	return (count);
}

static size_t	char_count(char const *s, char c, int start)
{
	size_t	count;

	count = 0;
	while (s[start] != c && s[start] != '\0')
	{
		count++;
		start++;
	}
	return (count);
}

static void		doit(char const *s, char **news, int i, char c)
{
	int		t;
	int		f;
	size_t	size;

	t = 0;
	while (s[i] != '\0')
	{
		f = 0;
		if (give_point(s, c, &i) == -1)
			break ;
		size = char_count(s, c, i);
		news[t] = (char*)malloc(sizeof(char) * (size + 1));
		if (!news[t])
			return ;
		while (s[i] != c && s[i] != '\0')
		{
			news[t][f] = s[i];
			i++;
			f++;
		}
		news[t][f] = '\0';
		if (s[i] == '\0')
			break ;
		t++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**news;
	size_t	size;

	size = words_count(s, c);
	news = (char**)malloc(sizeof(char*) * (size + 1));
	if (!news)
		return (0);
	news[size] = 0;
	doit(s, news, 0, c);
	return (news);
}
