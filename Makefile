NAME = libftprintf.a
HEAD = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c ft_printf_handle.c

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