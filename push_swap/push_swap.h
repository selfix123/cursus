/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:52:04 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 16:39:40 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_data
{
	int				content;
	int				index;
	struct s_data	*next;
	struct s_data	*previous;
	
}	t_data;

typedef struct s_piles
{
	int		a_count;
	int		b_count;
	t_data	*a;
	t_data	*b;
}	t_piles;

void	ft_dlstadd_back(t_data **lst, t_data *new);
t_data	*ft_dlstnew(int content);
void	ss(t_piles piles, bool print);
void	sb(t_data **b, bool print);
void	sa(t_data **a, bool print);
void	rrr(t_piles *piles, bool print);
void	rrb(t_data **data, bool print);
void	rra(t_data **data, bool print);
void	ra(t_data **data, bool print);
void	rb(t_data **data, bool print);
void	rr(t_piles *pile, bool print);
void	pa(t_piles *piles, bool print);
void	pb(t_piles *piles, bool print);
void	sort_three_a(t_piles *piles);
void	sort_four(t_piles *piles);
void	sort_five(t_piles *piles);
int	find_smallest_nbr(t_piles *piles);
void	printdata(t_data *data);
int	lstlen(t_data *data);

#endif
