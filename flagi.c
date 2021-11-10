/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 04:46:31 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 19:55:18 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	assigment_fl(void)
{
	t_list	struc;

	struc.width = 0;
	struc.star = 0;
	struc.name = 0;
	struc.otriz = 0;
	struc.null = 0;
	struc.dot = -1;
	return (struc);
}

int	specif(int c, t_list struc, va_list rg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = print_char(va_arg(rg, int), struc);
	else if (c == '%')
		count += print_percent(struc);
	else if (c == 'p')
		count = print_point(va_arg(rg, unsigned long long), struc);
	else if (c == 's')
		count = print_str(va_arg(rg, char *), struc);
	else if ((c == 'i') || (c == 'd'))
		count = print_int(va_arg(rg, int), struc);
	else if (c == 'x')
		count += print_hex(va_arg(rg, unsigned int), 1, struc);
	else if (c == 'X')
		count += print_hex(va_arg(rg, unsigned int), 0, struc);
	else if (c == 'u')
		count += print_uint((unsigned int)va_arg(rg, unsigned int), struc);
	return (count);
}

int	flagi(const char *s, int i, t_list *struc, va_list rg)
{
	while (s[i])
	{
		if (!ret_spec(s[i]) && !ret_flag(s[i])
			&& (!ft_isdigit(s[i])))
			break ;
		if (s[i] == '0' && struc->width == 0 && struc->otriz == 0)
			struc->null = 1;
		if (s[i] == '*')
			*struc = fl_width(rg, *struc);
		if (s[i] == '.')
			i = fl_dot(s, i, struc, rg);
		if (s[i] == '-')
			struc->otriz = 1;
		if (ft_isdigit(s[i]))
			*struc = fl_digit(s[i], *struc);
		if (ret_spec(s[i]))
		{
			struc->name = s[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ret_spec(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ret_flag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}
