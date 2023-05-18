/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:35:39 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/18 15:48:32 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digit(int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return(count);
}

int	max_digit(t_data *data)
{
	int	max_digit;
	int	max_num;
	int	digits;
	t_data	*ptr;

	max_digit = 0;
	max_num = 0;
	ptr = data;
	//digits = count_digit(ptr->content);
	//printf("%d\n", digits);
	ptr = ptr->next;
	while (ptr != data)
	{
		digits = count_digit(ptr->content);
		if (digits > max_digit)
		{
			max_digit = digits;
			max_num = ptr->content;
		}
		ptr = ptr->next;
	}
	return (max_digit);
}

void	radix_sort(t_piles *piles)
{
	int	j;
	int	max;
	t_data	*ptr;

	j = 0;
	ptr = piles->a;
	max = max_digit(piles->a);
	printf("%d\n", max);
	while (j < max)
	{
		while (ptr->next != piles->a)
		{
			printf("a:\n");
			printdata(piles->a);
			printf("b:\n");
			printdata(piles->b);
			if (((ptr->content >> 1) & 1) == 1)
				ra(&piles->a, 1);
			else
				pb(piles, 1);
			ptr = ptr->next;
		}
		j++;
	}
	while (j-- > 0)
		pa(piles, 1);
}
