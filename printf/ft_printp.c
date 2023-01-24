/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:30 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/11 13:12:10 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexaconversion(uintptr_t nb, int *len)
{
	if (nb > 15)
	{
		ft_hexaconversion(nb / 16, len);
		ft_hexaconversion(nb % 16, len++);
	}
	else
	{
		if (nb > 9)
			(*len) += ft_printc(nb + 87);
		else
			(*len) += ft_printc(nb + 48);
	}
}

int	ft_printp(uintptr_t nb)
{
	int	len;

	len = 2;
	ft_prints("0x");
	ft_hexaconversion(nb, &len);
	return (len);
}
