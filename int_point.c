/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:57:17 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 17:29:08 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_p(char *str, int n, t_list struc)
{
	int	c;

	c = 0;
	if (struc.dot >= 0 && n < 0 && n != -2147483648)
		ft_putchar('-');
	if (struc.dot >= 0)
		c += f_width(struc.dot - 1, ft_strlen(str) - 1, 1);
	c += printic(str, ft_strlen(str));
	return (c);
}

int	for_int(char *str, int n, t_list struc)
{
	int	c;

	c = 0;
	if (struc.otriz == 1)
		c += int_p(str, n, struc);
	if (struc.dot >= 0 && (size_t)struc.dot < ft_strlen(str))
		struc.dot = ft_strlen(str);
	if (struc.dot >= 0)
	{
		struc.width -= struc.dot;
		c += f_width(struc.width, 0, 0);
	}
	else
		c += f_width(struc.width, ft_strlen(str), struc.null);
	if (struc.otriz == 0)
		c += int_p(str, n, struc);
	return (c);
}

int	print_int(int i, t_list struc)
{
	int		c;
	int		num;
	char	*str;

	c = 0;
	num = i;
	if (struc.dot == 0 && i == 0)
	{
		c += f_width(struc.width, 0, 0);
		return (c);
	}
	if (i < 0 && (struc.dot >= 0 || struc.null == 1) && num != -2147483648)
	{
		if (struc.dot <= -1 && struc.null == 1)
			printic("-", 1);
		i *= -1;
		struc.null = 1;
		struc.width--;
		c++;
	}
	str = f_itoa(i);
	c += for_int(str, num, struc);
	free(str);
	return (c);
}

int	for_point(char *p, t_list struc)
{
	int	c;

	c = 0;
	c += printic("0x", 2);
	if (struc.dot >= 0)
	{
		c += f_width(struc.dot, ft_strlen(p), 1);
		c += printic(p, struc.dot);
	}
	else
		c += printic(p, ft_strlen(p));
	return (c);
}

int	print_point(unsigned long long n, t_list struc)
{
	int		c;
	char	*p;

	c = 0;
	if (struc.dot == 0 && !n)
	{
		if (struc.width >= 0 && struc.otriz == 0)
			(c += f_width(struc.width - 2, 0, 0))
				&& (c += printic("0x", 2));
		else
			(c += printic("0x", 2))
				&& (c += f_width(struc.width - 2, 0, 0));
		return (c);
	}
	p = print_base(n, 16);
	p = tolower_s(p);
	if ((size_t)struc.dot < ft_strlen(p))
		struc.dot = ft_strlen(p);
	if (struc.otriz == 1)
		c += for_point(p, struc);
	c += f_width(struc.width, ft_strlen(p) + 2, 0);
	if (struc.otriz == 0)
		c += for_point(p, struc);
	free(p);
	return (c);
}
