/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:13:40 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 00:31:05 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr(long nbr, int *printed);

void	ft_putint(int nbr, int *printed)
{
	long	lnbr;

	lnbr = nbr;
	if (lnbr < 0)
	{
		ft_putchar('-', printed);
		lnbr = -lnbr;
	}
	ft_putnbr(lnbr, printed);
}

static void	ft_putnbr(long nbr, int *printed)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10, printed);
	ft_putchar(nbr % 10 + '0', printed);
}
