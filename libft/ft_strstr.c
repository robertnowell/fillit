/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:54:44 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/21 16:54:46 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		do_match(const char *haystack, const char *needle, int i, int t)
{
	while (haystack[i] == needle[t] && needle[t] != '\0')
	{
		i++;
		t++;
	}
	if (needle[t] == '\0')
		return (1);
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (needle[0] == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			status = do_match(haystack, needle, i, 0);
			if (status == 1)
			{
				haystack += i;
				return ((char*)haystack);
			}
		}
		i++;
	}
	return (0);
}
