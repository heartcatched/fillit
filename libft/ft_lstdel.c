/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:31:08 by wzoltan           #+#    #+#             */
/*   Updated: 2019/09/28 14:51:12 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*el;
	t_list	*next_el;

	el = *alst;
	while (el != NULL)
	{
		next_el = el->next;
		del(el->content, el->content_size);
		free(el);
		el = next_el;
	}
	*alst = NULL;
}
