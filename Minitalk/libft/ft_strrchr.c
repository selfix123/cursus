/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:49:04 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 18:42:27 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			s = (char *)str;
		++str;
	}
	if (s)
		return (s);
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (NULL);
}
