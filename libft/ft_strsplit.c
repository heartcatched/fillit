/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:35:56 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/23 18:21:17 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f(char const *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static int		ft_word_length(char const *s, char c)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		res++;
		i++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * (f(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		if (!(str[i] = (char*)malloc(sizeof(char) * ft_word_length(s, c) + 1)))
			return (NULL);
		while (*s && *s != c)
			str[i][j++] = *s++;
		str[i++][j] = '\0';
		j = 0;
	}
	str[i] = NULL;
	return (str);
}
