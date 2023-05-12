/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 13:17:21 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_dlstnew(int content)
{
	t_data	*new;

	new = ft_calloc(sizeof(t_data), 1);
	if (!new)
		return (NULL);
	new->index = 0;
	new->content = content;
	new->next = new;
	new->previous = new;
	return (new);
}

void	ft_dlstadd_back(t_data **lst, t_data *new)
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

/* int	ft_lstlen(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return (0);
	while (data->next != data->head)
	{
		data = data->next;
		i++;
	}
	return (i);
} */
