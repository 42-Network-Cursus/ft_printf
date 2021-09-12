#include "ft_printf.h"



static int ft_check_format(char *spec, char c)
{
    while (*spec)
    {
        if (*spec == c)
            return (1);
        spec++;
    }
    return (0);
}

static int ft_specifier(va_list args, char c)
{
	int ret;

	if (ft_check_format("c", c))
	    ret += ft_handle_char(args);
	else if (ft_check_format("s", c))
		ret += ft_handle_string(args);
    else if (ft_check_format("p", c))
		ret += ft_handle_pointer(args, 'p');
	else if (ft_check_format("di", c))
        ret += ft_handle_int(args);
	else if (ft_check_format("u", c))
        ret += ft_handle_uint(args, 'u');
	else if (ft_check_format("xX", c))
        ret += ft_handle_hex(args, 'x');
	else if (ft_check_format("%", c))
        ret += write(1, "%", 1);
	return (ret);
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
			ret += ft_specifier(args, *(format + 1));
            format += 2;
        }
        else
            ret += write(1, &(*format++), 1);        
    }
    va_end(args);
    return (ret);
}

int main()
{
    char 			c = 'P';
    char   			*str = "TEST THIS";
	int				d = 123456789;
	unsigned int	u = 4294967295;
	size_t			p;
	printf("\nc conversion\n");
	printf("og ret = %d\n", printf("og = %c\n", c));
	printf("ft ret = %d\n", ft_printf("ft = %c\n", c));
	printf("\ns conversion\n");
	printf("og ret = %d\n", printf("og = %s\n", str));
	printf("ft ret = %d\n", ft_printf("ft = %s\n", str));
	printf("\np conversion\n");
	printf("og ret = %d\n", printf("og = %p\n", str));
	printf("ft ret = %d\n", ft_printf("ft = %p\n", str));
	printf("\nd conversion\n");
	printf("og ret = %d\n", printf("og = %d\n", d));
	printf("ft ret = %d\n", ft_printf("ft = %d\n", d));
	printf("\ni conversion\n");
	printf("og ret = %d\n", printf("og = %i\n", d));
	printf("ft ret = %d\n", ft_printf("ft = %i\n", d));
	printf("\nu conversion\n");
	printf("og ret = %d\n", printf("og = %u\n", u));
	printf("ft ret = %d\n", ft_printf("ft = %u\n", u));
	printf("\nx conversion\n");
	printf("og ret = %d\n", printf("og = %x\n", u));
	printf("ft ret = %d\n", ft_printf("ft = %x\n", u));
	printf("\nX conversion\n");
	printf("og ret = %d\n", printf("og = %X\n", u));
	printf("ft ret = %d\n", ft_printf("ft = %X\n", u));
	printf("\n% conversion\n");
	printf("og ret = %d\n", printf("og = %%\n", d));
	printf("ft ret = %d\n", ft_printf("ft = %%\n"));
    return (0);
}