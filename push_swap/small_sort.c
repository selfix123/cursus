/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:35 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 16:33:49 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_four(t_piles *piles)
{
	if (piles->a->previous->content == find_smallest_nbr(piles))
		rra(&piles->a, true);
	else
		ra(&piles->a, true);
	if (piles->a->content == find_smallest_nbr(piles))
	{
		pb(piles, true);
		sort_three_a(piles);
		pa(piles, true);
		return ;
	}
	sort_four(piles);
}

void	sort_five(t_piles *piles)
{
	t_data	*head;

	head = piles->a;
	if (head->previous->index == 1 || head->previous->previous->index == 1)
		rra(&piles->a, true);
	else
		ra(&piles->a, true);
	if (head->index == 1)
	{
		pb(piles, true);
		sort_four(piles);
		pa(piles, true);
		return ;
	}
	sort_five(piles);
}
