/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:07:46 by marvin            #+#    #+#             */
/*   Updated: 2022/10/19 13:07:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*dest;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(string) + 1;
	if (!string)
		return (0);
	dest = (char *)malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (string[i])
	{
		dest[i] = string[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
