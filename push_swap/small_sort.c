/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:35 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/24 13:38:11 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_piles *piles)
{
	if (piles->a->content > piles->a->next->content)
		sa(&piles->a, 1);
}

void	sort_two_b(t_piles *piles)
{
	if (piles->b->content < piles->b->next->content)
		sb(&piles->b, 1);
}

void	sort_three_a(t_data *a)
{
	t_data	*first;
	t_data	*middle;
	t_data	*last;

	first = a;
	middle = a->next;
	last = a->previous;
	if (first->content > last->content && first->content > middle->content)
	{
		printf("allo\n");
		ra(&a, 1);
		sort_three_a(a);
	}
	else if (first->content < middle->content && middle->content > last->content)
	{
		rra(&a, 1);
		sort_three_a(a);
	}
	else if (first->content > middle->content && first->content < last->content)
		sa(&a, true);
}

void	sort_three_b(t_piles *piles)
{
	t_data	*first;
	t_data	*middle;
	t_data	*last;

	first = piles->b;
	middle = piles->b->next;
	last = piles->b->previous;
	if (first->content < middle->content && first->content < last->content)
	{
		rb(&piles->b, 1);
		sort_three_b(piles);
	}
	else if (middle->content < first->content && middle->content < last->content)
	{
		rrb(&piles->b, 1);
		sort_three_b(piles);
	}
	else if (middle->content > first->content && middle->content > last->content)
		sb(&piles->b, true);
}

void	all_small_sort(t_piles *piles)
{
		if (piles->total > 3)
		{
			while (piles->a_count > 3)
			{
				printf("%d\n", piles->a_count);
				if (piles->a->content <= piles->total - 3)
					pb(piles, 1);
				else
				{
					printf("allo2\n");
					ra(&piles->a, 1);
				}
			}
		}
		if (piles->b_count == 2)
			sort_two_b(piles);
		else if (piles->b_count == 3)
			sort_three_b(piles);
		if (piles->a_count == 2)
			sort_two_a(piles);
		else if (piles->a_count == 3)
			sort_three_a(piles->a);
		while (piles->b_count > 0)
			pa(piles, 1);
}
