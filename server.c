/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:59:17 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 15:53:17 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_server(int signal);

int	main(void)
{
	ft_printf("My Server PID is %d\n", getpid());
	ft_printf(YELLOW "Waiting for a message...\n" RESET);
	while (1)
	{
		signal(SIGUSR1, ft_handle_server);
		signal(SIGUSR2, ft_handle_server);
		pause();
	}
	return (0);
}

void	ft_handle_server(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}
