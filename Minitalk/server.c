/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/21 12:59:55 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_data	g_data;

void	ft_free_struct(void)
{
	g_data.message = ft_xfree(g_data.message);
	g_data.client_pid = 0;
	g_data.bit = 0;
	g_data.c = 0;
}

static void	ft_clear_all(void)
{
	g_data.len = 0;
	if (g_data.message)
	{
		ft_putendl_fd(g_data.message, 1);
		g_data.message = ft_xfree(g_data.message);
	}
	g_data.i = 0;
}

static void	ft_msg_len(int *curr_bit, char **str, int *received, int signal)
{
	static int	len_val = 0;

	if (signal == SIGUSR2)
		len_val += ft_recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*received = 1;
		*str = ft_calloc_exit(len_val + 1, sizeof(char));
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	(void) context;
	if (!g_data.client_pid)
		g_data.client_pid = info->si_pid;
	if (g_data.client_pid != info->si_pid)
	{
		ft_free_struct();
		ft_clear_all();
	}
	if (!g_data.len)
		ft_msg_len(&g_data.bit, &g_data.message, &g_data.len, signal);
	else if (g_data.message)
	{
		if (signal == SIGUSR2)
			g_data.c += ft_recursive_power(2, g_data.bit);
		if (g_data.bit == 7)
		{
			g_data.message[g_data.i++] = g_data.c;
			g_data.bit = 0;
			if (g_data.c == 0)
				return (ft_clear_all());
			g_data.c = 0;
			return ;
		}
		g_data.bit++;
	}
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
		usleep(100);
	return (0);
}
