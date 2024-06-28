/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:50:45 by sabras            #+#    #+#             */
/*   Updated: 2024/05/22 19:21:29 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FORMATS "cspdiuxX%"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(int c, int *printed);
void	ft_putstr(char *str, int *printed);
void	ft_puthexa(unsigned long value, char *base, int *printed);
void	ft_putptr(unsigned long value, int *printed);
void	ft_putint(int nbr, int *printed);
void	ft_putuint(unsigned int nbr, int *printed);

#endif
