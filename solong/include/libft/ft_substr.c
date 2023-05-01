/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:46:09 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 18:47:35 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	int		j;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[j++])
			i++;
	dest = ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return (0);
	if (start >= ft_strlen(s))
		return (dest);
	ft_strlcpy(dest, &s[start], i + 1);
	return (dest);
}
