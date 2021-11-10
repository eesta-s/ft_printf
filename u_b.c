/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:56:21 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 19:26:56 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uint_p(char *u, t_list struc)
{
	int	c;

	c = 0;
	if (struc.dot >= 0)
		c += f_width(struc.dot - 1, ft_strlen(u) - 1, 1);
	c += printic(u, ft_strlen(u));
	return (c);
}

int	for_uint(char *u, t_list struc)
{
	int	c;

	c = 0;
	if (struc.otriz == 1)
		c += uint_p(u, struc);
	if (struc.dot >= 0 && (size_t)struc.dot < ft_strlen(u))
		struc.dot = ft_strlen(u);
	if (struc.dot >= 0)
	{
		struc.width -= struc.dot;
		c += f_width(struc.width, 0, 0);
	}
	else
		c += f_width(struc.width, ft_strlen(u), struc.null);
	if (struc.otriz == 0)
		c += uint_p(u, struc);
	return (c);
}

int	print_uint(unsigned int n, t_list struc)
{
	int		c;
	char	*u;

	c = 0;
	if (struc.dot == 0 && n == 0)
	{
		c += f_width(struc.width, 0, 0);
		return (c);
	}
	u = u_itoa(n);
	c = for_uint(u, struc);
	free(u);
	return (c);
}

static char	*ft_base(unsigned long long n, int b, int c, char *s)
{
	while (n != 0)
	{
		if ((n % b) < 10)
			s[c - 1] = (n % b) + 48;
		else
			s[c - 1] = (n % b) + 55;
		n /= b;
		c--;
	}
	return (s);
}

char	*print_base(unsigned long long n, int b)
{
	unsigned long long	i;
	int					c;
	char				*s;

	i = n;
	s = 0;
	c = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= b;
		c++;
	}
	s = malloc(c + 1);
	if (!s)
		return (0);
	s[c] = '\0';
	s = ft_base(i, b, c, s);
	return (s);
}
