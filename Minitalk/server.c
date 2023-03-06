/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:10:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/06 14:41:34 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

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

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR2)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}
/*
void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void) context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		printf("%c", c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}
*/

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		printf("\033[91mError: wrong format.\033[0m\n");
		printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}
