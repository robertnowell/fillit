/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:58:58 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/27 10:24:26 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (0);
	ft_strcpy(dup, s1);
	return (dup);
}
