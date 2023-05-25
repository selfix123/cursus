/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:31:37 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/25 15:29:08 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_double(t_data *data, int ac)
{
	t_data	*current;
	t_data	*next;
	t_data	*head;

	head = data;
	current = data;
	next = data;
	if (!data)
		return (0);
	while (--ac)
	{
		while (current->next != head)
		{
			if (current->content == next->content)
				return (1);
			else
				return (0);
			current = current->next;
		}
	}
	return (0);
}
