/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:02:50 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 18:31:24 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int	i;

	i = 0;
	if (!(str1 && str2))
		return (0);
	if (n <= 0)
		return (0);
	while (((unsigned char *)str1)[i] == ((unsigned char *) str2)[i] && --n > 0)
	{
		i++;
	}
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
