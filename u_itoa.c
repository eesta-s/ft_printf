/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:12:01 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 22:04:52 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_itoa(unsigned int n)
{
	if (n < 10)
		return (1);
	else
		return (for_itoa(n / 10) + 1);
}

static int	ft_length(int c)
{
	int		len;
	long	nb;

	len = 1;
	nb = c;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*f_itoa(int n)
{
	char	*src;
	long	nbr;
	int		i;

	i = 0;
	src = malloc(sizeof(char) * ft_length(n) + 1);
	if (!src)
		return (NULL);
	if (n < 0)
		src[0] = '-';
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	src[ft_length(n) - i++] = '\0';
	while (nbr >= 10)
	{
		src[ft_length(n) - i++] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	src[ft_length(n) - i++] = (nbr % 10) + 48;
	return (src);
}

char	*for_uitoa(char *num, long n, int d, int c)
{
	if (n != 0)
		num = malloc(sizeof(char) * (d + 1));
	else
		return (num = ft_strdup("0"));
	if (!num)
		return (0);
	c = 0;
	if (n < 0)
	{
		c++;
		n = -n;
	}
	num[d] = '\0';
	while (--d)
	{
		num[d] = (n % 10) + '0';
		n /= 10;
	}
	if (d == 1)
		num[0] = '-';
	else
		num[0] = (n % 10) + '0';
	return (num);
}

char	*u_itoa(unsigned int i)
{
	int		d;
	char	*num;
	long	n;
	int		c;

	n = i;
	d = for_itoa(n);
	num = 0;
	c = 0;
	num = for_uitoa(num, n, d, c);
	if (!num)
		return (0);
	return (num);
}
