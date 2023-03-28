/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/28 10:43:34 by zbeaumon         ###   ########.fr       */
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

/*static void	ft_clear_all(void)
{
	g_data.len = 0;
	if (g_data.message)
	{
		ft_putendl_fd(g_data.message, 1);
		g_data.message = ft_xfree(g_data.message);
	}
	g_data.i = 0;
}
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
*/

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
	if (!g_data.client_pid)
		g_data.client_pid = info->si_pid;
	if (info->si_pid != g_data.client_pid)
		ft_cleanserver(&binairy, &received);
	if (signal == SIGUSR1)
		received |= (1 << binairy);
	binairy++;
	if (binairy == 8)
	{	
		if (!received)
		{
			kill(info->si_pid, SIGUSR1);
			ft_putendl_fd(g_data.message, 1);
			g_data.message = ft_xfree(g_data.message);
		}
		else
			g_data.message = ft_constructstr(g_data.message, received);
		binairy = 0;
		received = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

/*
static void	ft_msg_len(int *curr_bit, char **str, int *received, int signal)
{
	static int	len_val = 0;

	if (signal == SIGUSR2)
		len_val += ft_recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*received = 1;
		*str = ft_calloc_exit(len_val + len_val, sizeof(char));
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}
*/
/*
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
	if (g_data.message)
	{
		if (signal == SIGUSR2)
			g_data.c += ft_recursive_power(2, g_data.bit);
		if (g_data.bit == 8)
		{
			kill(info->si_pid, SIGUSR1);
			g_data.message[g_data.i++] = g_data.c;
			g_data.bit = 0;
			if (g_data.c == 0)
				ft_clear_all();
			g_data.c = 0;
		}
		g_data.bit++;
	}
	kill(info->si_pid, SIGUSR2);
}
*/

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
