/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:34:33 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/16 16:53:15 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_;
	unsigned char	*src_;
	size_t			i;

	i = 0;
	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	while (i < n)
	{
		dest_[i] = src_[i];
		if (src_[i] == (unsigned char)c)
			return (dest_ + i + 1);
		i++;
	}
	return (NULL);
}
