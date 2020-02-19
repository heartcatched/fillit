/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:12:17 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/23 18:20:49 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_mincheck(int *n, char *str)
{
	if (*n == -2147483648)
	{
		*str = '-';
		*(str + 1) = '2';
		*n = 147483648;
	}
}

static int		ft_num_ch(int n)
{
	int		res;

	res = 0;
	if (n == -2147483648)
	{
		n = 147483648;
		res = 2;
	}
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		n = -n;
	}
	while (n > 0)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_num_ch(n);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	ft_mincheck(&n, str);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}
