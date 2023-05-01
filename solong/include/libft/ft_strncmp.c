/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:35:52 by marvin            #+#    #+#             */
/*   Updated: 2022/10/19 13:35:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	if (!(str1 && str2))
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && n > 0)
	{		
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
