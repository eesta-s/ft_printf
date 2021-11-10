/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ch_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:48:13 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 17:03:01 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_str(char *str, t_list struc)
{
	int	count;

	count = 0;
	if (struc.dot >= 0)
	{
		count += f_width(struc.dot, ft_strlen(str), 0);
		count += printic(str, struc.dot);
	}
	else
		count += printic(str, ft_strlen(str));
	return (count);
}

int	print_str(char *str, t_list struc)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (struc.dot >= 0 && (size_t)struc.dot > ft_strlen(str))
		struc.dot = ft_strlen(str);
	if (struc.otriz == 1)
		count += for_str(str, struc);
	if (struc.dot >= 0)
		count += f_width(struc.width, struc.dot, 0);
	else
		count += f_width(struc.width, ft_strlen(str), 0);
	if (struc.otriz == 0)
		count += for_str(str, struc);
	return (count);
}

int	print_char(char c, t_list struc)
{
	int	count;

	count = 0;
	if (struc.otriz == 1)
		ft_putchar(c);
	count = f_width(struc.width, 1, 0);
	if (struc.otriz == 0)
		ft_putchar(c);
	return (count + 1);
}

int	print_percent(t_list struc)
{
	int	c;

	c = 0;
	if (struc.otriz == 1)
		c += printic("%", 1);
	c += f_width(struc.width, 1, struc.null);
	if (struc.otriz == 0)
		c += printic("%", 1);
	return (c);
}
