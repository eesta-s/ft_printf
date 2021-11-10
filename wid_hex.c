/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wid_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:42:28 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 19:26:13 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_width(int width, int otriz, int null)
{
	int	c;

	c = 0;
	while (width > otriz)
	{
		if (null)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		c++;
	}
	return (c);
}

int	hex_p(char *x, t_list struc)
{
	int	c;

	c = 0;
	if (struc.dot >= 0)
	{
		c += f_width(struc.dot - 1, ft_strlen(x) - 1, 1);
	}
	c += printic(x, ft_strlen(x));
	return (c);
}

int	for_hex(char *x, t_list struc)
{
	int	c;

	c = 0;
	if (struc.otriz == 1)
		c += hex_p(x, struc);
	if (struc.dot >= 0 && (size_t)struc.dot < ft_strlen(x))
		struc.dot = ft_strlen(x);
	if (struc.dot >= 0)
	{
		struc.width -= struc.dot;
		c += f_width(struc.width, 0, 0);
	}
	else
	{
		c += f_width(struc.width, ft_strlen(x), struc.null);
	}
	if (struc.otriz == 0)
		c += hex_p(x, struc);
	return (c);
}

int	print_hex(unsigned int n, int i, t_list struc)
{
	char	*x;
	int		c;

	c = 0;
	if (struc.dot == 0 && n == 0)
	{
		c += f_width(struc.width, 0, 0);
		return (c);
	}
	x = print_base((unsigned long long)n, 16);
	if (i == 1)
		x = tolower_s(x);
	c += for_hex(x, struc);
	free(x);
	return (c);
}
