/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:43 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/19 10:26:09 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	normal_push(t_data **a, t_data **b)
// {
// 	t_data	*head_a;
// 	t_data	*head_b;

// 	head_a = (*a)->next;
// 	head_a->previous = (*a)->previous;
// 	head_a->previous->next = head_a;
// 	head_b = (*a);
// 	if (!(*a) || !(*b))
// 	{
// 		head_b->next = head_b;
// 		head_b->previous = head_b;
// 		(*a) = NULL;
// 		if (lstlen(head_a) > 1)
// 			(*a) = head_a;
// 		(*b) = head_b;
// 		return ;
// 	}
// 	else
// 	{
// 		head_b->next = (*b);
// 		head_b->previous = (*b)->previous;
// 		head_b->next->previous = head_b;
// 		head_b->previous->next = head_b;
// 		(*a) = NULL;
// 		lstlen(head_a);
// 		if (lstlen(head_a) > 1)
// 			(*a) = head_a;
// 		(*b) = head_b;
// 	}
// }

// // void	empty(t_data **a, t_data **b)
// // {
// // 	t_data	*heada;
// // 	t_data	*headb;

// // 	heada = (*a)->next;
// // 	heada->previous = (*a)->previous;
// // 	heada->previous->next = heada;
// // 	headb = (*a);
// // 	headb->next = headb;
// // 	headb->previous = headb;
// // 	(*a) = heada;
// // 	(*b) = headb;
// // }

// void	pa(t_piles *piles)
// {
// 	if (!piles->b)
// 		return ;
// 	normal_push(&piles->b, &piles->a);
// 	ft_putendl_fd("pa", 1);
// }

// void	pb(t_piles *piles)
// {
// 	if (!piles->a)
// 		return ;
// 	if (!piles->b)
// 	{
// 		normal_push(&piles->a, &piles->b);
// 		ft_putendl_fd("pb", 1);
// 	}
// }

static void	std_push(t_data **a, t_data **b)
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
	(*a) = head_a;
	(*b) = head_b;
}

static void	empty_push(t_data **a, t_data **b)
{
	t_data	*head_a;
	t_data	*head_b;

	head_a = (*a)->next;
	head_a->previous = (*a)->previous;
	head_a->previous->next = head_a;
	head_b = (*a);
	head_b->next = head_b;
	head_b->previous = head_b;
	(*a) = head_a;
	(*b) = head_b;
}

static void	last_push(t_data **a, t_data **b)
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

void	pa(t_piles *piles, bool print)
{
	if (!piles->b)
		return ;
	if (piles->a_count == 0)
		empty_push(&piles->b, &piles->a);
	else if (piles->b_count == 1)
		last_push(&piles->b, &piles->a);
	else
		std_push(&piles->b, &piles->a);
	piles->a_count++;
	piles->b_count--;
	if (print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_piles *piles, bool print)
{
	if (!piles->a)
		return ;
	if (piles->b_count == 0)
		empty_push(&piles->a, &piles->b);
	else if (piles->a_count == 1)
		last_push(&piles->a, &piles->b);
	else
		std_push(&piles->a, &piles->b);
	piles->b_count++;
	piles->a_count--;
	if (print)
		ft_putendl_fd("pb", 1);
}
