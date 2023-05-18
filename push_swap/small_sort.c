/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:35 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/18 13:24:10 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_piles *piles)
{
	if (is_list_in_order(piles->a))
		sa(&piles->a, 1);
}

void	sort_two_b(t_piles *piles)
{
	if (is_list_in_order(piles->b))
		sb(&piles->b, 1);
}

void	sort_three_a(t_piles *piles)
{
	int	first;
	int	middle;
	int	last;

	first = piles->a->content;
	middle = piles->a->next->content;
	last = piles->a->previous->content;
	if (first > middle && first > last)
	{
		ra(&piles->a, 1);
		sort_three_a(piles);
	}
	else if (first < middle && middle > last)
	{
		rra(&piles->a, 1);
		sort_three_a(piles);
	}
	else if (first > middle && first < last)
	{
		sa(&piles->a, true);
		sort_three_a(piles);
	}
}

void	sort_three_b(t_piles *piles)
{
	int	first;
	int	middle;
	int	last;

	first = piles->a->content;
	middle = piles->a->next->content;
	last = piles->a->previous->content;
	if (first < middle && first < last)
	{
		rb(&piles->a, 1);
		sort_three_a(piles);
	}
	else if (first > middle && middle < last)
	{
		rrb(&piles->a, 1);
		sort_three_a(piles);
	}
	else if (first < middle && first > last)
	{
		sb(&piles->a, true);
		sort_three_a(piles);
	}
}

void	all_small_sort(t_piles *piles)
{
	if (piles->a_count > 3)
	{
		while (piles->a_count > 3)
			{
				if (piles->b_count == 1)
					pa(piles, 1);
				else
					ra(&piles->a, 1);
			}
	}
	if (piles->a_count == 2)
		sort_two_a(piles);
	if (piles->b_count == 2)
		sort_two_b(piles);
	if (piles->a_count == 3)
		sort_three_a(piles);
	if (piles->b_count == 3)
		sort_three_b(piles);
}
