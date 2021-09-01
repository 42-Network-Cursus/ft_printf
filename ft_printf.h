#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> //malloc, free
# include <unistd.h> //write
# include <stdarg.h> //va_start/arg/copy/end

int ft_printf(const char *, ...);

#endif