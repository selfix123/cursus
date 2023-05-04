/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:32 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/04 12:47:17 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_data **data, bool print)
{
	(*data) = (*data)->previous;
	if (print == true)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrb(t_data **data, bool print)
{
	(*data) = (*data)->previous;
	if (print == true)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_piles piles, bool print)
{
	ft_rra(&piles.a, false);
	ft_rrb(&piles.b, false);
	if (print == true)
		ft_putendl_fd("rrr", 1);
}
