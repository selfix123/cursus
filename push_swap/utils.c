/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/04 14:06:16 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_dlstnew(void *content)
{
	t_data	*new;

	new = ft_calloc(sizeof(t_data), 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = new;
	new->previous = new;
	return (new);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		last = (*lst)->previous;
		last->next = new;
		new->previous = last;
		new->next = (*lst);
		(*lst)->previous = new;
	}
}
