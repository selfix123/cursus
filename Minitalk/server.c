/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/29 12:53:15 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_data	g_data;

static void	ft_cleanserver(int *binairy, int *received)
{
	g_data.message = ft_xfree(g_data.message);
	g_data.client_pid = 0;
	*binairy = 0;
	*received = 0;
}

static char	*ft_constructstr(char *src, int bit)
{
	int		len_src;
	char	*res;
	char	c;
	int		i;

	i = 0;
	c = (char)bit;
	len_src = ft_strlen(src);
	res = ft_calloc(len_src + 2, sizeof(char));
	if (src)
	{
		while (src[i])
		{
			res[i] = src[i];
			i++;
		}
	}
	res[i] = c;
	ft_xfree(src);
	return (res);
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	binairy;
	static int	received;

	(void) context;
	if (g_data.client_pid != info->si_pid && info->si_pid != 0)
		ft_cleanserver(&binairy, &received);
	if (!g_data.client_pid)
		g_data.client_pid = info->si_pid;
	if (signal == SIGUSR1)
		received |= (1 << binairy);
	if (++binairy == 8)
	{
		if (!received)
		{
			ft_putendl_fd(g_data.message, 1);
			kill(g_data.client_pid, SIGUSR1);
			ft_cleanserver(&binairy, &received);
			return ;
		}
		else
			g_data.message = ft_constructstr(g_data.message, received);
		binairy = 0;
		received = 0;
	}
	kill(g_data.client_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void) argv;
	if (argc != 1)
	{
		ft_putstr_fd ("\033[0;31mWrong input.Try ./server only!", 1);
		ft_putchar_fd('\n', 1);
		return (-1);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
