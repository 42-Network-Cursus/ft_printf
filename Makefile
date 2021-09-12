# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwastche </var/mail/cwastche>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 17:32:32 by cwastche          #+#    #+#              #
#    Updated: 2021/09/12 18:23:42 by cwastche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEAD = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c ft_printf_handle.c ft_printf_handle2.c

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c $(HEAD)
	$(CC) $(CLFAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
