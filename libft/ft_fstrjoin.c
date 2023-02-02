/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:49:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/31 10:42:37 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrjoin(char *s1free, char *s2)
{
	size_t	str1;
	size_t	str2;
	char	*dest;

	str1 = ft_strlen(s1free);
	str2 = ft_strlen(s2);
	dest = ft_calloc(str1 + str2 + 1, sizeof(char));
	if (!dest)
		return (ft_xfree(dest), NULL);
	while (str1 + str2-- > str1)
		dest[str1 + str2] = s2[str2];
	while (str1--)
		dest[str1] = s1free[str1];
	if (*dest == 0)
		dest = ft_xfree(dest);
	return (ft_xfree(s1free), dest);
}
