/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:35 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/25 15:30:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_piles *piles)
{
	if (piles->a->content > piles->a->next->content)
		sa(&piles->a, piles->a_count, 1);
}

void	sort_two_b(t_piles *piles)
{
	if (piles->b->content < piles->b->next->content)
		sb(&piles->b, piles->b_count, 1);
}

void	sort_three_a(t_piles *piles)
{
	t_data	*first;
	t_data	*mid;
	t_data	*last;

	first = piles->a;
	mid = piles->a->next;
	last = piles->a->previous;
	if (first->content > last->content && first->content > mid->content)
	{
		ra(&piles->a, 1);
		sort_three_a(piles);
	}
	else if (first->content < mid->content && mid->content > last->content)
	{
		rra(&piles->a, 1);
		sort_three_a(piles);
	}
	else if (first->content > mid->content && first->content < last->content)
		sa(&piles->a, piles->a_count, true);
}

void	sort_three_b(t_piles *piles)
{
	t_data	*first;
	t_data	*mid;
	t_data	*last;

	first = piles->b;
	mid = piles->b->next;
	last = piles->b->previous;
	if (first->content < mid->content && first->content < last->content)
	{
		rb(&piles->b, 1);
		sort_three_b(piles);
	}
	else if (mid->content < first->content && mid->content < last->content)
	{
		rrb(&piles->b, 1);
		sort_three_b(piles);
	}
	else if (mid->content > first->content && mid->content > last->content)
		sb(&piles->b, piles->b_count, true);
}

void	all_small_sort(t_piles *piles)
{
	if (piles->total > 3)
	{
		while (piles->a_count > 3)
		{
			if (piles->a->content <= piles->total - 3)
				pb(piles, 1);
			else
				ra(&piles->a, 1);
		}
	}
	if (piles->b_count == 2)
		sort_two_b(piles);
	else if (piles->b_count == 3)
		sort_three_b(piles);
	if (piles->a_count == 2)
		sort_two_a(piles);
	else if (piles->a_count == 3)
		sort_three_a(piles);
	while (piles->b_count > 0)
		pa(piles, 1);
}
