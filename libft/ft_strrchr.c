/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:56:35 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/19 19:00:01 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	if (c == '\0')
		return (str + ft_strlen(s));
	while (ft_strlen(s) >= i)
	{
		if (str[ft_strlen(s) - i] == c)
			return (str + ft_strlen(s) - i);
		i++;
	}
	return (NULL);
}
