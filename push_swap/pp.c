/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:43 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/08 10:26:50 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normal_push(t_data **a, t_data **b)
{
	t_data	*head_a;
	t_data	*head_b;

	head_a = (*a)->next;
	head_a->previous = (*a)->previous;
	head_a->previous->next = head_a;
	head_b = (*a);
	head_b->next = (*b);
	head_b->previous = (*b)->previous;
	head_b->next->previous = head_b;
	head_b->previous->next = head_b;
	(*a) = head_b;
	(*b) = head_b;
}

void	empty(t_data **a, t_data **b)
{
	t_data	*heada;
	t_data	*headb;

	heada = (*a)->next;
	heada->previous = (*a)->previous;
	heada->previous->next = heada;
	headb = (*a);
	headb->next = headb;
	headb->previous = headb;
	(*a) = heada;
	(*b) = headb;
}

void	last_push(t_data **a, t_data **b)
{
	t_data	*head_b;

	head_b = (*a);
	head_b->next = (*b);
	head_b->previous = (*b)->previous;
	head_b->next->previous = head_b;
	head_b->previous->next = head_b;
	(*a) = NULL;
	(*b) = head_b;
}

void	ft_pa(t_piles *piles)
{
	if (!piles->b)
		return ;
	if (piles->a_count == 0)
		empty(&piles->a, &piles->b);
	else if (piles->b_count == 1)
		last_push(&piles->a, &piles->b);
	else
		normal_push(&piles->a, &piles->b);
	piles->a_count++;
	piles->b_count--;
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_piles *piles)
{
	if (!piles->a)
		return ;
	if (piles->b_count == 0)
		empty(&piles->a, &piles->b);
	else if (piles->a_count == 1)
		last_push(&piles->a, &piles->b);
	else
		normal_push(&piles->a, &piles->b);
	piles->a_count--;
	piles->b_count++;
	ft_putendl_fd("pb", 1);
}
