/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/02/23 13:36:01 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_received(int signal)
{
	static int	i;
	static int	bits;

	if (signal == SIGUSR1)
		i |= (0x01 << bits);
	if (bits == 8)
	{
		printf("%c", i);
		i = 0;
		bits = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("the pid of the server is: %d\n", pid);
	signal(SIGUSR1, ft_received);
	signal(SIGUSR2, ft_received);
	while (1)
		sleep(1);
	return (0);
}
