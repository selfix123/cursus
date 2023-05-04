/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:34 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/04 12:46:09 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_data **data, bool print)
{
	(*data) = (*data)->next;
	if (print == true)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_data **data, bool print)
{
	(*data) = (*data)->next;
	if (print == true)
		ft_putendl_fd("rb", 1);
}

void	ft_rr(t_piles *pile, bool print)
{
	ft_ra(&pile->a, true);
	ft_rb(&pile->b, true);
	if (print == true)
		ft_putendl_fd("rr", 1);
}
