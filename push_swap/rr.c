/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:34 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/08 15:38:54 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data **data, bool print)
{
	(*data) = (*data)->next;
	if (true)
		ft_putendl_fd("ra", 1);
}

void	rb(t_data **data, bool print)
{
	(*data) = (*data)->next;
	if (true)
		ft_putendl_fd("rb", 1);
}

void	rr(t_piles *pile, bool print)
{
	ra(&pile->a, true);
	rb(&pile->b, true);
	if (true)
		ft_putendl_fd("rr", 1);
}
