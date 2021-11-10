/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:38:09 by eesta             #+#    #+#             */
/*   Updated: 2021/06/08 14:10:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
 int ret;

 ft_printf("%04d\n", -532);
 printf("%04d\n", -532);
 ft_printf("%0d\n", -54);
 printf("%0d\n", -54);
 ft_printf("%04d\n", -4825);
 printf("%04d\n", -4825);
 ft_printf("%X\n", 25);
 printf("%X\n", 25);
 ret = ft_printf("%p %013d %-.7i %-10u %x\n", &ret, -234, -876, 183, 545);
 printf("printf returns %d bytes\n", ret);
 ret = printf("%p %013d %-.7i %-10u %x\n", &ret, -234, -876, 183, 545);
 printf("printf returns %d bytes\n", ret);
 ft_printf("%s\n", "Hello from printf!");
 printf("%s\n", "Hello from printf!");
 ft_printf("wuy%%%%%%%%%%uwe\n");
 printf("wuy%%%%%%%%%%uwe\n");
 ft_printf("");
 printf("");
 ft_printf("%d\n", 0);
 printf("%d\n", 0);
 ft_printf("%.6d\n", -3);
 printf("%.6d\n", -3);
 ft_printf("%   .6d\n", -3);
 printf("%   .6d\n", -3);
 ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
 printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
 ft_printf("%5c\n", 'A');
 printf("%5c\n", 'A');
 ft_printf("%     d\n", 0);
 printf("%     d\n", 0);
 printf("%20.1s\n", "eisjfvhiehvr");
 ft_printf("%20.1s\n", "eisjfvhiehvr");
 char *s = 0;
 ft_printf("%20s\n", s);
 printf("%20s\n", s);
 ft_printf("%s\n", s);
 printf("%s\n", s);
 ft_printf("%20.5s\n", "elsjfhvbelhrv");
 printf("%20.5s\n", "elsjfhvbelhrv");
 return (0);
}
