/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:28:08 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/26 14:15:32 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		news[i] = f(i, *s);
		s++;
		i++;
	}
	news[i] = '\0';
	return (news);
}
