/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:52:04 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/24 13:15:50 by zbeaumon         ###   ########.fr       */
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
	int		total;
	t_data	*a;
	t_data	*b;
}	t_piles;

void	ft_dlstadd_back(t_data **lst, int *temp, int i, int ac);
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
void	sort_three_a(t_data *a);
int		find_smallest_nbr(t_piles *piles);
int		find_biggest_nbr(t_piles *piles);
void	printdata(t_data *data);
int		lstlen(t_data *data);
int		is_list_in_order(t_data *data);
void	radix_sort(t_piles *piles);
void	all_small_sort(t_piles *piles);
char	**get_total_args(int *ac, char **av);
void	sort_two_a(t_piles *piles);
void	sort_two_b(t_piles *piles);
int	*temp_array(int ac, char **av);

#endif
