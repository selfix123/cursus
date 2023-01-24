/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:51:02 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/15 11:05:27 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlenhexa(unsigned int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	ft_hexaconversion(unsigned int nb, char c)
{
	int	i;

	i = 0;
	if (c == 'x')
		i = 87;
	else if (c == 'X')
		i = 55;
	if (nb > 15)
	{
		ft_hexaconversion(nb / 16, c);
		ft_hexaconversion(nb % 16, c);
	}
	else
	{
		if (nb > 9)
			ft_putchar_fd(nb + i, 1);
		else
			ft_putchar_fd(nb + 48, 1);
	}
}

int	ft_printx(unsigned int nb, char c)
{
	ft_hexaconversion(nb, c);
	return (ft_intlenhexa(nb));
}
