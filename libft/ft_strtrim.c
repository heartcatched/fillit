/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:10:53 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/23 18:25:26 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_wsp_inbegin(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static size_t	ft_count_wsp_inend(char const *s)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
	{
		len--;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	beg;
	size_t	end;

	if (s == NULL)
		return (NULL);
	beg = ft_count_wsp_inbegin(s);
	end = ft_count_wsp_inend(s);
	if ((int)ft_strlen(s) - (int)beg - (int)end <= 0)
	{
		str = (char*)malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = ft_strnew(ft_strlen(s) - beg - end);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s) - ft_count_wsp_inbegin(s) - end)
		str[i++] = s[beg++];
	str[i] = '\0';
	return (str);
}
