/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 13:14:33 by zbeaumon         ###   ########.fr       */
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

void	sa(t_data **a)
{
	if ((*a)->next != (*a) && (*a)->next->next != (*a))
		ft_swap_node(a);
	else
		ra(a, true);
}

void	sb(t_data **b)
{
	if ((*b)->next != (*b) && (*b)->next->next != (*b))
		ft_swap_node(b);
	else
		ra(b, true);
}

void	ss(t_piles piles, bool print)
{
	(void)print;
	sa(&piles.a);
	sb(&piles.b);
	if (print)
		ft_putendl_fd("ss", 1);
}
