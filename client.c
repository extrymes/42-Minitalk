/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:59:19 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 11:51:31 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char c)
{
	
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	if (ac != 3)
		return (ft_printf(RED "Usage: <pid> <msg>\n" RESET), 1);
	pid = ft_atoi(av[1]);
	msg = av[2];
	i = 0;
	while (msg[i])
		ft_send_signal(pid, msg[i++]);
	return (0);
}
