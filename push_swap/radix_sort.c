/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:35:39 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/23 15:24:29 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_piles *piles)
{
	int		j;
	int		i;

	j = 0;
	while (is_list_in_order(piles->a))
	{
		i = 0;
		while (i++ < piles->total)
		{
			if (((piles->a->content >> j) & 1) == 1)
				ra(&piles->a, 1);
			else
				pb(piles, 1);
		}
		j++;
		while (piles->b_count != 0)
			pa(piles, 1);
	}
}
