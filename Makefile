# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eesta <eesta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 16:23:03 by eesta             #+#    #+#              #
#    Updated: 2021/06/02 16:37:53 by eesta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		flag_s.c \
		flagi.c \
		str_ch_proc.c \
		int_point.c \
		wid_hex.c \
		u_b.c \
		u_itoa.c \
		libft.c

OBJ			= $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re