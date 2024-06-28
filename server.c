/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:59:17 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 11:51:13 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_server(int signal)
{
	
}

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
