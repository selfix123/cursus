/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:35 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 12:33:18 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_piles *piles)
{
	int	first;
	int	middle;
	int	last;

	first = piles->a->index;
	middle = piles->a->next->index;
	last = piles->a->previous->index;
	if (first < middle && middle > last && first < last)
	{
		ra(&piles->a, 1);
		sort_three_a(piles);
	}
	if (first > middle && middle < last && first > last)
	{
		rra(&piles->a, 1);
		sort_three_a(piles);
	}
	if (first > middle && middle < last && first < last)
	{
		sa(&piles->a);
		sort_three_a(piles);
	}
}

void	sort_four(t_piles *piles)
{
	t_data	*head;

	head = piles->a;
	if (head->previous->index == 1)
		rra(piles->a, true);
	else
		ra(piles->a, true);
	if (head->index == 1)
	{
		pb(piles->b);
		sort_three_a(piles->a);
		pa(piles->a);
		return ;
	}
	sort_four(piles);
}

void	sort_five(t_piles *piles)
{
	t_data	*head;

	head = piles->a;
	if (head->previous->index == 1 || head->previous->previous->index == 1)
		rra(piles->a, true);
	else
		ra(piles->a, true);
	if (head->index == 1)
	{
		pb(piles->b);
		sort_four(piles->a);
		pa(piles->a);
		return ;
	}
	sort_five(piles);
}
