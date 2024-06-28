/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:56:09 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 00:31:05 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putuint(unsigned int nbr, int *printed)
{
	if (nbr >= 10)
		ft_putuint(nbr / 10, printed);
	ft_putchar(nbr % 10 + '0', printed);
}
