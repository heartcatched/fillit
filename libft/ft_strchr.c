/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:37:11 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/18 17:56:19 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;

	src = (char*)s;
	if (c == '\0')
		return (src + ft_strlen(src));
	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (src + i);
		i++;
	}
	return (NULL);
}
