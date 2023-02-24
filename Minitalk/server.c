/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/02/24 17:11:43 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	catchsignal(int sig, siginfo_t info)
{
	static int		i;
	static char		c;
	static pid_t	client_pid;

	if (!client_pid)
		client_pid = info.si_pid;
	c |= (sig == SIGUSR2);
}
/*static	void	ft_received(int signal)
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
*/

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("the pid of the server is: %d\n", pid);
	sigaction(SIGUSR1, &sa_sigaction, 0);
	sigaction(SIGUSR2, &sa_sigaction, 0);
	while (1)
		sleep(1);
	return (0);
}
