/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:50:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 16:00:50 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_biggest_nbr(t_piles *piles)
// {
// 	int		max;
// 	t_data	*head;

// 	head = piles->a;
// 	max = piles->a->content;
// 	while (piles->a->next != head)
// 	{
// 		if (piles->a->next->content > max)
// 			max = piles->a->next->content;
// 		piles->a = piles->a->next;
// 	}
// 	return (max);
// }

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
	data = data->next;
	i++;
	while (data != head)
	{
		data = data->next;
		i++;
	}
	printf("%d\n", i);
	return (i);
}

// void	index_lst(t_piles *piles)
// {
// 	int	i;
// 	int	index;

// 	i = 0;
// 	index = 0;
// 	if (!piles)
// 		return ;
// 	while (ft_lstlen(piles->a))
// 	{
// 		if (piles->a->content < piles->a->next->content)
// 			piles->a->index = i;
// 	}
// }
