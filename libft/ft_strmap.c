/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:22:25 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 14:14:32 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	s_len;
	char	*news;
	int		i;

	s_len = ft_strlen(s);
	news = (char*)malloc(sizeof(char) * (s_len + 1));
	if (!news)
		return (0);
	i = 0;
	while (*s)
	{
		news[i] = f(*s);
		i++;
		s++;
	}
	news[i] = '\0';
	return (news);
}
