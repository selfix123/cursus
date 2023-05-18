/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/13 12:45:09 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_node(t_data **data)
{
	t_data	*head;
	t_data	*tmp;

	tmp = *data;
	head = (*data)->next;
	head->previous = tmp->previous;
	tmp->next = head->next;
	tmp->previous = head;
	head->next = tmp;
	head->previous->next = head;
	tmp->previous->next = tmp;
	(*data) = head;
}

void	sa(t_data **a, bool print)
{
	if ((*a)->next != (*a) && (*a)->next->next != (*a))
	{
		if (print)
			ft_putendl_fd("sa", 1);
		ft_swap_node(a);
	}
	else
		ra(a, print);
}

void	sb(t_data **b, bool print)
{
	if ((*b)->next != (*b) && (*b)->next->next != (*b))
	{
		if (print)
			ft_putendl_fd("sb", 1);
		ft_swap_node(b);
	}
	else
		ra(b, print);
}

void	ss(t_piles piles, bool print)
{
	sa(&piles.a, false);
	sb(&piles.b, false);
	if (print)
		ft_putendl_fd("ss", 1);
}
