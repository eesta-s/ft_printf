/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 04:58:35 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 19:30:15 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	fl_digit(char c, t_list struc)
{
	if (struc.star == 1)
		struc.width = 0;
	struc.width = (struc.width * 10) + (c - 48);
	return (struc);
}

t_list	fl_width(va_list rg, t_list struc)
{
	struc.star = 1;
	struc.width = va_arg(rg, int);
	if (struc.width < 0)
	{
		struc.otriz = 1;
		struc.width *= -1;
		struc.null = 0;
	}
	return (struc);
}

int	fl_dot(const char *s, int c, t_list *struc, va_list rg)
{
	int	i;

	i = c;
	i = i + 1;
	if (s[i] == '*')
	{
		struc->dot = va_arg(rg, int);
		i = i + 1;
	}
	else
	{
		struc->dot = 0;
		while (ft_isdigit(s[i]))
		{
			struc->dot = (struc->dot * 10) + (s[i] - 48);
			i = i + 1;
		}
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	printic(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
