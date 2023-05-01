/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:08:52 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/10/31 12:42:32 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int nb)
{	
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*dest;
	long int	nb;

	nb = n;
	i = ft_intlen(nb);
	dest = (char *)malloc (sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i-- > 0)
	{
		if (nb < 0)
		{
			dest[0] = '-';
			nb *= -1;
		}
		while (nb > 9 && i > 0)
		{
			dest[i--] = (nb % 10) + 48;
			nb /= 10;
		}
		dest[i--] = nb + 48;
	}
	return (dest);
}
