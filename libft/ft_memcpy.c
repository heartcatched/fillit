/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:47:39 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/16 16:23:46 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	buf1 = (unsigned char*)dest;
	buf2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		buf1[i] = buf2[i];
		i++;
	}
	return (dest);
}
