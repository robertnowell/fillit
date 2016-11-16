/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 16:24:33 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 14:26:11 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	news = (char*)malloc(sizeof(char) * (s1_len + s2_len));
	if (!news)
		return (0);
	while (*s1)
	{
		news[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		news[i] = *s2;
		s2++;
		i++;
	}
	news[i] = '\0';
	return (news);
}
