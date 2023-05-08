/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:35 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/08 15:46:00 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data **data, t_piles *piles)
{
	if ((*data) < (*data)->next && (*data)->next < (*data)->previous
		&& (*data) < (*data)->previous)
		return ;
	if ((*data) > (*data)->next && (*data)->next > (*data)->previous
		&& (*data) > (*data)->previous)
	{
		sa(&piles->a);
		ra(&piles->a, true);
	}
	if ((*data) > (*data)->next && (*data)->next < (*data)->previous
		&& (*data) > (*data)->previous)
	{
		rra(&piles->a, true);
		ra(&piles->a, true);
	}
	if ((*data) < (*data)->next && (*data)->next > (*data)->previous)
	{
		rra(&piles->a, true);
		sa(&piles->a);
	}
}

void	sort_five(t_data **data)
{
}

void	sort_four(t_data **data)
{
}
