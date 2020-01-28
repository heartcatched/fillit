/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:04:14 by wzoltan           #+#    #+#             */
/*   Updated: 2019/11/27 17:19:34 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char		*fub[2000];
	char			buf[BUFF_SIZE + 1];
	char			*join;
	int				rd;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (fub[fd] == NULL)
			fub[fd] = ft_strdup(buf);
		else
		{
			join = ft_strjoin(fub[fd], buf);
			free(fub[fd]);
			fub[fd] = join;
		}
		if (ft_strchr(fub[fd], '\n'))
			break ;
	}
	return (result(rd, fd, fub, line));
}

int		result(int rd, int fd, char **fub, char **line)
{
	if (rd == 0 && fub[fd] == NULL)
		return (0);
	if (rd == -1)
		return (-1);
	return (get_line(fub, fd, line));
}

int		get_line(char **fub, int fd, char **line)
{
	int		i;
	char	*tmp2;

	i = 0;
	while ((fub[fd][i] != '\n') && (fub[fd][i] != '\0'))
		i++;
	if (fub[fd][i] == '\n')
	{
		*line = ft_strsub(fub[fd], 0, i);
		tmp2 = ft_strdup(fub[fd] + i + 1);
		free(fub[fd]);
		fub[fd] = tmp2;
		if (fub[fd][0] == '\0')
		{
			free(fub[fd]);
			fub[fd] = NULL;
		}
	}
	else
	{
		*line = ft_strdup(fub[fd]);
		free(fub[fd]);
		fub[fd] = NULL;
	}
	return (1);
}
