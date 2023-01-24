/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:31:23 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 18:28:47 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*a;
	const char	*b;

	i = 0;
	a = dest;
	b = src;
	if (!(dest && src))
		return (0);
	if (a == NULL && b == NULL)
		return (NULL);
	while (n-- > 0)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
