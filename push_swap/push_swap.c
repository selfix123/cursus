/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:25 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/19 15:44:27 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;

	i = 1;
	ft_bzero(&piles, sizeof(t_piles));
	//index_lst(&piles);
	//printdata(piles.a);
	piles.total = ac - 1;
	piles.a_count = ac - 1;
	piles.a = ft_dlstnew(ft_atoi(av[1]));
	while (++i < ac)
		ft_dlstadd_back(&piles.a, ft_dlstnew(ft_atoi(av[i])));
	radix_sort(&piles);
	printf("\npiles a\n");
	printdata(piles.a);
	printf("\npiles b\n");
	printdata(piles.b);
}
