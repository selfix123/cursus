/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:20:47 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 18:33:34 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (0);
	while (i <= len)
	{
		if (((char *)str)[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
