/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:43:26 by eesta             #+#    #+#             */
/*   Updated: 2021/06/03 00:38:32 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_printf(const char *s, va_list rg)
{
	int		i;
	int		c;
	t_list	struc;

	i = 0;
	c = 0;
	while (s[i] && s)
	{
		struc = assigment_fl();
		if (s[i] != '%')
			c += ft_putchar(s[i]);
		else if (s[i] == '%' && s[i + 1])
		{
			i = flagi(s, ++i, &struc, rg);
			if (ret_spec(s[i]))
				c += specif((char)struc.name, struc, rg);
			else
				c += ft_putchar(s[i]);
		}
		i++;
	}
	return (c);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		rg;
	const char	*s;
	int			c;

	s = ft_strdup(fmt);
	if (!s)
		return (0);
	va_start(rg, fmt);
	c = for_printf(s, rg);
	va_end(rg);
	free((char *)s);
	return (c);
}
