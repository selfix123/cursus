/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:31:37 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/11 15:34:43 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_double(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			else
				return (0);
			j++;
		}
		i++;
	}
}
