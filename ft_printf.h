#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

# include <stdlib.h> //malloc, free
# include <unistd.h> //write
# include <stdarg.h> //va_start/arg/copy/end

int ft_printf(const char *, ...);
int	ft_putnbr_base_int(int nb, char *base);
int	ft_putnbr_base(size_t nb, char *base, int base_len, char c);
int ft_handle_char(va_list args);
int ft_handle_string(va_list args);
int ft_handle_pointer(va_list args, char c);
int ft_handle_int(va_list args);
int ft_handle_uint(va_list args, char c);
int ft_handle_hex(va_list args, char c);
int ft_handle_hex_upper(va_list args, char c);
size_t	ft_strlen(const char *s);

#endif