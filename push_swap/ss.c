/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/25 13:40:59 by zbeaumon         ###   ########.fr       */
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

void	sa(t_data **a, int count, bool print)
{
	if (count > 2)
		ft_swap_node(a);
	else
		ra(a, 0);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_data **b, int count, bool print)
{
	if (count > 2)
		ft_swap_node(b);
	else
		rb(b, 0);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_piles piles, bool print)
{
	sa(&piles.a, piles.a_count, false);
	sb(&piles.b, piles.b_count, false);
	if (print)
		ft_putendl_fd("ss", 1);
}
