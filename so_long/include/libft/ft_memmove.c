/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:18:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 19:43:13 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	if (str1 > str2)
		while (n-- > 0)
			((char *)str1)[n] = ((char *)str2)[n];
	else
	{
		while (i < n)
		{
			((char *)str1)[i] = ((char *)str2)[i];
			i++;
		}
	}
	return ((char *)str1);
}
