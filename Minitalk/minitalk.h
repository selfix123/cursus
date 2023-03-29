/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:15:21 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/29 12:53:23 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include<stdio.h>
# include<signal.h>
# include "libft/libft.h"

typedef struct s_data
{
	int		bit;
	int		i;
	int		len;
	char	c;
	char	*message;
	int		client_pid;
}	t_data;

typedef struct s_cdata
{
	char	*message;
	int		i;
	int		current_bit;
	int		spid;
	int		length;
}			t_cdata;

#endif