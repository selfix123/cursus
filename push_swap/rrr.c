/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:32 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 15:04:10 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data **data, bool print)
{
	(*data) = (*data)->previous;
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_data **data, bool print)
{
	(*data) = (*data)->previous;
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_piles *piles, bool print)
{
	rra(&piles->a, false);
	rrb(&piles->b, false);
	if (print)
		ft_putendl_fd("rrr", 1);
}
