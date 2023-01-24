/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:09:48 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/14 13:28:05 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_printc(int c);
int				ft_prints(char *str);
int				ft_print_pourc(char c);
int				ft_printx(unsigned int nb, char c);
int				ft_printi(int nb);
int				ft_printp(uintptr_t nb);
int				ft_printu(unsigned int nb);
#endif