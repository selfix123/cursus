/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:58:25 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/14 13:26:14 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_printc(va_arg(args, int));
	else if (f == 's')
		len += ft_prints(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		len += ft_printi(va_arg(args, int));
	else if (f == 'u')
		len += ft_printu(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len += ft_printx(va_arg(args, unsigned int), f);
	else if (f == 'p')
		len += ft_printp(va_arg(args, uintptr_t));
	else if (f == '%')
		len += ft_print_pourc(37);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		len;

	va_start(lst, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(lst, str[i + 1]);
			i++;
		}
		else
			len += ft_printc(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
