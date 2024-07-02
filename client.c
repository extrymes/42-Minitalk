/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:59:19 by sabras            #+#    #+#             */
/*   Updated: 2024/07/02 22:14:45 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_response;

void	ft_sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	g_response = 1;
	if (signum == SIGUSR1)
		ft_printf("Bytes received: \033[32m%d\033[0m\n", i / 8);
	else if (signum == SIGUSR2)
		i++;
}

int	ft_char_to_bin(char c, int srv_pid)
{
	int	itr;
	int	bit_idx;

	bit_idx = 7;
	while (bit_idx >= 0)
	{
		if ((c >> bit_idx) & 1)
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		itr = 0;
		while (g_response == 0)
		{
			if (itr == 50)
			{
				ft_printf(RED "No response from server" RESET, 1);
				exit(1);
			}
			itr++;
			usleep(100);
		}
		g_response = 0;
		bit_idx--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					srv_pid;
	int					i;

	if (ac != 3)
		return (ft_printf(RED "Usage:\t./client [SRV_PID] [MESSAGE]\n" RESET), 1);
	srv_pid = ft_atoi(av[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf(RED "Sigaction error\n" RESET, 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf(RED "Sigaction error\n" RESET, 1);
	i = 0;
	while (av[2][i])
		ft_char_to_bin(av[2][i++], srv_pid);
	ft_char_to_bin('\0', srv_pid);
	return (0);
}
