/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:34 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 15:40:16 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data **data, bool print)
{
	(*data) = (*data)->next;
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_data **data, bool print)
{
	(*data) = (*data)->next;
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_piles *pile, bool print)
{
	ra(&pile->a, true);
	rb(&pile->b, true);
	if (print)
		ft_putendl_fd("rr", 1);
}
