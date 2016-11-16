/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:53:40 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 14:24:53 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	s_len;
	int		i;

	i = 0;
	news = (char*)malloc(sizeof(char) * (len + 1));
	if (!news)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (0);
	while (s[start] && len)
	{
		news[i] = s[start];
		start++;
		i++;
		len--;
	}
	news[i] = '\0';
	return (news);
}
