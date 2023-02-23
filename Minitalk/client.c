/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:09:50 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/02/23 15:07:31 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_action(int sig)
{
	int	received;

	received = 0;
	if (sig == SIGUSR1)
		received++;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static	void	ft_kill(int pid, char *str)
{
	int		i;

	while (str)
	{
		i = 8;
		while (i--)
		{
			if (i == 0x01)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	ft_kill(11, argv[2]);
	while (1)
		sleep(1);
	return (0);
}
