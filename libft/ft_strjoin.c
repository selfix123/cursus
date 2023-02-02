/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:21:43 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/12/11 17:29:46 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	dest = (char *)malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
		dest[j++] = s1[i++];
	while (s2[k] != '\0')
		dest[j++] = s2[k++];
	dest[j] = '\0';
	return (dest);
}
