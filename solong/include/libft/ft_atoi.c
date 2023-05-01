/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:30:30 by marvin            #+#    #+#             */
/*   Updated: 2022/10/19 13:30:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	res;

	count = 1;
	res = 0;
	if (!str)
		return (0);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		count = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (count * res);
}
