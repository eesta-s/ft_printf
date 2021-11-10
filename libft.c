/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:49:01 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 21:48:56 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tolower_s(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	s = malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!s)
		return (NULL);
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
