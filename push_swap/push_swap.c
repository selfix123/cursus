/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:25 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/25 15:41:54 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_algo(t_piles *piles)
{
	if (piles->total == 2)
		sort_two_a(piles);
	if (piles->total > 2 && piles->total < 7)
		all_small_sort(piles);
	else
		radix_sort(piles);
}

void	printdata(t_data *data)
{
	t_data	*head;

	head = data;
	if (!data)
	{
		printf("(null)\n");
		return ;
	}
	printf("%d\n", data->content);
	data = data->next;
	while (data != head)
	{
		printf("%d\n", data->content);
		data = data->next;
	}
}

int	main(int ac, char **av)
{
	t_piles	piles;
	int		*temp;
	int		i;

	i = -1;
	temp = temp_array(ac, av);
	ft_bzero(&piles, sizeof(t_piles));
	piles.total = ac - 1;
	piles.a_count = ac - 1;
	while (++i < ac - 1)
		ft_dlstadd_back(&piles.a, temp, i, ac);
	if (is_list_in_order(piles.a))
		select_algo(&piles);
	printf("\n");
	printf("a\n");
	printdata(piles.a);
	printf("\n");
	printf("b\n");
	printdata(piles.b);
	printf("\n");
}
