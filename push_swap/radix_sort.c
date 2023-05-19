/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:35:39 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/19 17:19:31 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	count_digit(int nb)
// {
// 	int	count;

// 	count = 0;
// 	while (nb != 0)
// 	{
// 		nb /= 10;
// 		count++;
// 	}
// 	return (count);
// }

// int	max_digit(t_data *data)
// {
// 	int		max_digit;
// 	int		max_num;
// 	int		digits;
// 	t_data	*ptr;

// 	max_digit = 0;
// 	max_num = 0;
// 	ptr = data;
// 	digits = count_digit(ptr->content);
// 	ptr = ptr->next;
// 	while (ptr != data)
// 	{
// 		digits = count_digit(ptr->content);
// 		if (digits > max_digit)
// 		{
// 			max_digit = digits;
// 			max_num = ptr->content;
// 		}
// 		ptr = ptr->next;
// 	}
// 	return (max_digit);
// }

int	find_max_bit(long max)
{
	long	bit;
	int		i;

	i = 1;
	bit = 2;
	while (max > bit)
	{
		bit *= 2;
		i++;
	}
	return (i);
}

void	radix_sort(t_piles *piles)
{
	int		j;
	int		max;
	t_data	*ptr;

	ptr = piles->a;
	j = 0;
	max = find_max_bit(find_biggest_nbr(piles));
	while (j < max)
	{
		while (ptr != piles->a)
		{
			if (((ptr->content >> 1) & 1) == 1)
				ra(&piles->a, 1);
			else
				pb(piles, 1);
			ptr = ptr->next;
		}
		j++;
		while (j <= piles->b_count)
		{
			pa(piles, 1);
			j--;
		}
	}
}
