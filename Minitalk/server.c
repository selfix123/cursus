/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/07 15:21:17 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_msg = 0;

char	*ft_stringstore(char *str, char c)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	new = malloc(len + 2 * sizeof(char));
	ft_memmove(new, str, len);
	new[len] = c;
	new[len] = '\0';
	ft_xfree(str);
	return (new);
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;
	static int	client_id = 0;

	(void) context;
	if (!client_id)
		client_id = info->si_pid;
	if (signal == SIGUSR2)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		g_msg = ft_stringstore(g_msg, i);
		ft_putstr_fd(g_msg, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void)argv;
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_handler;
	printf("%d\n", getpid());
	sigaction(SIGUSR2, &action, 0);
	sigaction(SIGUSR1, &action, 0);
	while ("Destiny is the best game")
		;
	return (0);
}
