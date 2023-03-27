/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:09:50 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/27 15:43:17 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_cdata	g_cdata;

/*void	ft_send_bits(unsigned char c, int pid)
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
*/

static void	ft_init(char **av)
{
	g_cdata.current_bit = 0;
	g_cdata.i = -1;
	g_cdata.message = av[2];
	g_cdata.spid = ft_atoi(av[1]);
	g_cdata.length = ft_strlen(g_cdata.message);
}
/*
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
	}
}
*/

static void	ft_sender(int signb, siginfo_t *server, void *unused)
{
	(void) unused;
	(void) server;
	if (signb == SIGUSR2)
	{
		ft_putendl_fd("sending", 1);
		if (g_cdata.length)
		{
			if (g_cdata.message[g_cdata.i] & (1 << g_cdata.current_bit))
				kill(g_cdata.spid, SIGUSR1);
			else
				kill(g_cdata.spid, SIGUSR2);
			g_cdata.current_bit++;
			if (g_cdata.current_bit == 8)
			{
				g_cdata.i++;
				g_cdata.current_bit = 0;
				g_cdata.length--;
			}
		}
	}
	else if (signb == SIGUSR1)
	{
		ft_putendl_fd("terminated", 1);
		exit(EXIT_SUCCESS);
	}
	else if (signb == -1)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	char				*err_message;

	err_message = "invalid amount of arguments, 3 needed\n";
	act.sa_sigaction = &ft_sender;
	act.sa_flags = SA_SIGINFO;
	ft_init(av);
	if (ac == 3)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		//ft_send_len(ft_strlen(av[2]), g_cdata.spid);
		kill(getpid(), SIGUSR2);
		while (3)
			pause();
	}
	else
		ft_putstr_fd(err_message, 1);
}
/*int	main(int argc, char **argv)
{
	int				pid;
	int				i;
	int				len;
	char			*str_to_send;

	if (argc != 3)
	{
		ft_putendl_fd("\033[0;35mWrong input../client takes pid and message", 1);
		return (-1);
	}
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
	return (0);
}
*/