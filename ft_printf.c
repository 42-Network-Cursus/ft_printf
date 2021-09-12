#include "ft_printf.h"

#include <stdio.h>

size_t	ft_strlen(const char *s) //OG
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_base_int(int nb, char *base)
{
	char	str[30];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (nb == 0)
		len = write(1, "0", 1);
	if (nb == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (nb < 0)
	{
		nb = -nb;
		len += write(1, "-", 1);
	}
	while (nb)
	{
		str[i++] = base[nb % 10];
		nb /= 10;
	}
	while (i--)
		len += write(1, &str[i], 1);
	return (len);
}

int	ft_putnbr_base(size_t nb, char *base, int base_len, char c)
{
	char	str[30];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (c == 'p')
		len += write(1, "0x", 2);
	if (nb == 0)
		len += write(1, "0", 1);
	while (nb)
	{
		str[i++] = base[nb % base_len];
		nb /= base_len;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

static int ft_check_format(char *conv, char c)
{
    int i;

    i = 0;
    while (*conv && !i)
    {
        if (*conv == c)
            i = 1;
        conv++;
    }
    return (i);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     ret;
     
    va_start(args, format);
    ret = 0;
    while (*format)
    {
        if (*format == '%' && ft_check_format("cspdiuxX%", *(format + 1)))
        {
            if (ft_check_format("c", *(format + 1)))
                ret += ft_handle_char(args);
            else if (ft_check_format("s", *(format + 1)))
                ret += ft_handle_string(args);
            else if (ft_check_format("p", *(format + 1)))
              ret += ft_handle_pointer(args, 'p');
			else if (ft_check_format("di", *(format + 1)))
                ret += ft_handle_int(args);
			else if (ft_check_format("u", *(format + 1)))
                ret += ft_handle_uint(args, 'u');
			else if (ft_check_format("x", *(format + 1)))
                ret += ft_handle_hex(args, 'x');
			else if (ft_check_format("X", *(format + 1)))
                ret += ft_handle_hex_upper(args, 'X');
			else if (ft_check_format("%", *(format + 1)))
                ret += write(1, "%", 1);
            format += 2;
        }
        else
            ret += write(1, &(*format++), 1);        
    }
    va_end(args);
    return (ret);
}
/*
int main()
{
    char 			c = 'P';
    char   			*str = NULL;
	int				d = 0;
	unsigned int	u = 4294967295;
	size_t			p;

//	c conversion
//	printf("og ret = %d\n", printf("og = %c\n", c));
//	printf("ft ret = %d\n", ft_printf("ft = %c\n", c));

//	s conversion
//	printf("og ret = %d\n", printf("og = %s\n", str));
//	printf("ft ret = %d\n", ft_printf("ft = %s\n", str));

//	p conversion
	printf("og ret = %d\n", printf("og = %p\n", str));
	printf("ft ret = %d\n", ft_printf("ft = %p\n", str));

//	d conversion
//	printf("og ret = %d\n", printf("og = %d\n", d));
//	printf("ft ret = %d\n", ft_printf("ft = %d\n", d));

//	i conversion
//	printf("og ret = %d\n", printf("og = %i\n", d));
//	printf("ft ret = %d\n", ft_printf("ft = %i\n", d));

//	u conversion
//	printf("og ret = %d\n", printf("og = %u\n", u));
//	printf("ft ret = %d\n", ft_printf("ft = %u\n", u));

//	x conversion
//	printf("og ret = %d\n", printf("og = %x\n", u));
//	printf("ft ret = %d\n", ft_printf("ft = %x\n", u));

//	X conversion
//	printf("og ret = %d\n", printf("og = %X\n", u));
//	printf("ft ret = %d\n", ft_printf("ft = %X\n", u));

//	% conversion
//	printf("og ret = %d\n", printf("og = %%\n", d));
//	printf("ft ret = %d\n", ft_printf("ft = %%\n"));
    return (0);
}*/
