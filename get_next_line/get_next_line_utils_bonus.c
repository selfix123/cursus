/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:15 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/12/11 18:40:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *ptr, size_t size)
{
	while (size--)
		((char *)ptr)[size] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	new = malloc(count * size);
	if (!new)
		return (ft_xfree(new), NULL);
	ft_bzero(new, count * size);
	return (new);
}

void	*ft_xfree(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1free, char *s2)
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
