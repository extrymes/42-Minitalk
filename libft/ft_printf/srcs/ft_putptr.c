/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:03:53 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 00:31:05 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putptr(unsigned long value, int *printed)
{
	if (!value)
		return (ft_putstr("(nil)", printed));
	ft_putstr("0x", printed);
	ft_puthexa(value, "0123456789abcdef", printed);
}
