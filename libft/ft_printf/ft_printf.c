/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:49:41 by sabras            #+#    #+#             */
/*   Updated: 2024/06/28 13:27:36 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_data(va_list args, const char c, int *printed);
static int	ft_is_valid_format(char c);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;

	va_start(args, str);
	printed = 0;
	if (!str)
		return (va_end(args), -1);
	while (*str)
	{
		if (*str == '%' && !*(str + 1))
			return (va_end(args), -1);
		if (*str == '%' && ft_is_valid_format(*(str + 1)))
			ft_print_data(args, *(++str), &printed);
		else
			ft_putchar(*str, &printed);
		str++;
	}
	va_end(args);
	return (printed);
}

static void	ft_print_data(va_list args, const char c, int *printed)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), printed);
	if (c == 's')
		ft_putstr(va_arg(args, char *), printed);
	if (c == 'p')
		ft_putptr(va_arg(args, unsigned long), printed);
	if (c == 'd' || c == 'i')
		ft_putint(va_arg(args, int), printed);
	if (c == 'u')
		ft_putuint(va_arg(args, unsigned int), printed);
	if (c == 'x')
		ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef", printed);
	if (c == 'X')
		ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF", printed);
	if (c == '%')
		ft_putchar('%', printed);
}

static int	ft_is_valid_format(char c)
{
	int	i;

	i = 0;
	while (FORMATS[i])
	{
		if (c == FORMATS[i])
			return (1);
		i++;
	}
	return (0);
}
