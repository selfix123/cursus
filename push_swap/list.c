/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:50:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/24 13:09:55 by zbeaumon         ###   ########.fr       */
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

	head = data;
	if (!data)
		return (0);
	while (data->next != head)
	{
		if (data->content < data->next->content)
			data = data->next;
		else
			return (1);
	}
	return (0);
}

int	*temp_array(int ac, char **av)
{
	int	i;
	int	*temp;

	i = -1;
	temp = ft_calloc(ac, sizeof(int));
	while (++i < ac - 1)
		temp[i] = ft_atoi(av[i + 1]);
	return (temp);
}
