/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:43:12 by eesta             #+#    #+#             */
/*   Updated: 2021/06/02 22:05:37 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int	star;
	int	width;
	int	null;
	int	otriz;
	int	name;
	int	dot;
}		t_list;

int				flagi(const char *s, int i, t_list *struc, va_list rg);
int				specif(int c, t_list struc, va_list rg);
int				ret_flag(int c);
int				ret_spec(int c);
t_list			assigment_fl(void);
t_list			fl_digit(char c, t_list struc);
t_list			fl_width(va_list rg, t_list struc);
int				fl_dot(const char *s, int c, t_list *struc, va_list rg);
int				print_hex(unsigned int n, int i, t_list struc);
int				hex_p(char *x, t_list struc);
int				for_hex(char *x, t_list struc);
int				print_int(int i, t_list struc);
int				for_int(char *str, int n, t_list struc);
int				int_p(char *str, int n, t_list struc);
int				print_percent(t_list struc);
int				print_point(unsigned long long n, t_list struc);
int				for_point(char *p, t_list struc);
int				print_char(char c, t_list struc);
int				print_str(char *str, t_list struc);
int				for_str(char *str, t_list struc);
int				print_uint(unsigned int n, t_list struc);
int				uint_p(char *u, t_list struc);
int				for_uint(char *u, t_list struc);
char			*print_base(unsigned long long n, int b);
int				f_width(int width, int otriz, int null);
int				ft_printf(const char *fmt, ...);
int				for_printf(const char *s, va_list rg);
char			*f_itoa(int n);
int				for_itoa(unsigned int n);
char			*ft_strnew(int i);
char			*for_uitoa(char *num, long n, int d, int c);
char			*u_itoa(unsigned int n);
int				ft_putchar(char c);
int				ft_isdigit(int c);
char			*tolower_s(char *str);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
int				printic(char *str, int precision);

#endif
