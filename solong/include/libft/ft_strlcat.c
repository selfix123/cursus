/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:59:03 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 18:37:06 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;

	len = ft_strlen(dst);
	if (!(dst && src))
		return (0);
	if (dstsize <= len)
		return (dstsize + ft_strlen(src));
	dstsize -= len + 1;
	while (*src && dstsize-- > 0)
	{
		dst[len++] = *src++;
		dst[len] = 0;
	}
	return (len + ft_strlen(src));
}
