/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:50:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/18 10:25:56 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_nbr(t_piles *piles)
{
	int		max;
	t_data	*head;

	head = piles->a;
	max = piles->a->content;
	while (piles->a->next != head)
	{
		if (piles->a->next->content > max)
			max = piles->a->next->content;
		piles->a = piles->a->next;
	}
	return (max);
}

int	find_smallest_nbr(t_piles *piles)
{
	int		min;
	t_data	*head;

	head = piles->a;
	min = piles->a->content;
	while (head->next != piles->a)
	{
		if (head->next->content < min)
			min = head->next->content;
		head = head->next;
	}
	return (min);
}

int	lstlen(t_data *data)
{
	t_data	*head;
	int		i;

	i = 0;
	head = data;
	if (!data)
		return (0);
	while (data->next != head)
	{
		data = data->next;
		i++;
	}
	return (i);
}

int	is_list_in_order(t_data *data)
{
	t_data	*head;
	int		i;

	head = data;
	i = 0;
	if (!data)
		return (0);
	while (data != head)
	{
		if (data < data->next)
		{
			data = data->next;
			i++;
		}
		else
			return (i);
		data = data->next;
		i++;
	}
	return (i);
}

void	index_lst(t_piles *piles)
{
	int		index;
	t_data	*ptr;
	t_data	*current_node;

	current_node = piles->a;
	if (!piles)
		return ;
	while (current_node->next != piles->a)
	{
		index = 0;
		ptr = piles->a;
		while (ptr != piles->a)
		{
			if (piles->a->content < piles->a->next->content)
				piles->a->index = index;
			piles->a = piles->a->next;
			index++;
			ptr = ptr->next;
		}
		current_node->content = index + 1;
		current_node = current_node->next;
	}
}
