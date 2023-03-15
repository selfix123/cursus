/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/15 11:12:20 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static void	ft_clear_all(int *len, char **str, int *i)
{
	*len = 0;
	if (str)
	{
		printf("\033[0;36m");
		printf("%s\n", *str);
		//ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;
	static int	len = 0;
	static char	c = 0;
	static char	*message = 0;

	(void) context;
	(void) info;
	if (!len)
		ft_msg_len(&bit, &message, &len, signal);
	else
	{
		if (signal == SIGUSR2)
			c += ft_recursive_power(2, bit);
		if (bit == 7)
		{
			message[i++] = c;
			bit = 0;
			if (c == 0)
				return (ft_clear_all(&len, &message, &i));
			c = 0;
			return ;
		}
		bit++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void) argv;
	if (argc != 1)
	{
		ft_putstr_fd ("\033[0;31mWrong input.Try ./server", 1);
		ft_putchar_fd('\n', 1);
		return (-1);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	printf("%d\n", getpid());
	while (1)
		usleep(100);
	return (0);
}
