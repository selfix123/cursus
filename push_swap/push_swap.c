/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:25 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/12 13:47:18 by zbeaumon         ###   ########.fr       */
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
	t_piles	*piles;
	int		i;

	i = 1;
	piles = ft_calloc(3, sizeof(t_piles *));
	piles->a = ft_dlstnew(ft_atoi(av[1]));
	while (++i < ac)
		ft_dlstadd_back(&piles->a, ft_dlstnew(ft_atoi(av[i])));
	ra(&piles->a, 1);
	printf("piles a\n");
	printdata(piles->a);
	printf("piles b\n");
	printdata(piles->b);
}
