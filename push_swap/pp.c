/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:43 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 13:31:42 by zbeaumon         ###   ########.fr       */
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
	if (!(*a) || !(*b))
	{
		head_b->next = head_b;
		head_b->previous = head_b;
		(*a) = NULL;
	}
	else
	{
		head_b->next = (*b);
		head_b->previous = (*b)->previous;
		head_b->next->previous = head_b;
		head_b->previous->next = head_b;
	}
	(*a) = head_a;
	(*b) = head_b;
}

// void	empty(t_data **a, t_data **b)
// {
// 	t_data	*heada;
// 	t_data	*headb;

// 	heada = (*a)->next;
// 	heada->previous = (*a)->previous;
// 	heada->previous->next = heada;
// 	headb = (*a);
// 	headb->next = headb;
// 	headb->previous = headb;
// 	(*a) = heada;
// 	(*b) = headb;
// }

void	ft_pa(t_piles *piles)
{
	if (!piles->b)
		return ;
	if (!piles->a)
	{		
		normal_push(&piles->a, &piles->b);
		ft_putendl_fd("pa", 1);
	}
}

void	ft_pb(t_piles *piles)
{
	if (!piles->a)
		return ;
	if (!piles->b)
	{
		normal_push(&piles->a, &piles->b);
		ft_putendl_fd("pb", 1);
	}
}
