/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:59:19 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 15:53:21 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_signal(int pid, char c);

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	if (ac != 3)
		return (ft_printf(RED "Usage: ./client <pid> <msg>\n" RESET), 1);
	pid = ft_atoi(av[1]);
	msg = av[2];
	i = 0;
	while (msg[i])
		ft_send_signal(pid, msg[i++]);
	return (0);
}

static void	ft_send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}
