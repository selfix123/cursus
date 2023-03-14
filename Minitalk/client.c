/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:09:50 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/14 14:10:25 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_msgreceived(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr_fd("Message received", 1);
	else
		ft_putstr_fd("Message not received", 1);
}

void	ft_send_bits(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

void	ft_send_len(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	int				i;
	int				len;
	char			*str_to_send;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (-1);
		str_to_send = argv[2];
		len = ft_strlen(str_to_send);
		i = -1;
		ft_send_len(len, pid);
		while (str_to_send[++i])
			ft_send_bits(str_to_send[i], pid);
		ft_send_bits(str_to_send[i], pid);
	}
}
