#include "ft_printf.h"

// TODEL

#include <stdio.h>
// 1. Quid bonus?
// 2. Make it work : cspdiuxX% ! No buffer management (?)
//      c = unsigned char
//      s = const char * expected
//      p = hexadecimal as if by %#x
//      d = signed conv. signed decimal int ! no diff with i
//      i = int
//      u = unsigned decimal
//      x = convert in unsigned hexa using abcdef
//      X = convert in unsigned hexa using ABCDEF
// %[$][flags][width][.precision][length modifier]conversion - order
// 3. Errors + return msg
// 4. free when malloc

// TODEL
static int check_format(const char *format, va_list ptr)
{
    int     ret;

    ret = 1;
/*
    if (*format == 'c')
    else if (*format == 's')
    else if (*format == 'p')
    else if (*format == 'd') O if - or . O ignored
    else if (*format == 'i') O if - or . O ignored
    else if (*format == 'u') O if - or . O ignored
    else if (*format == 'x') #O if - or . O ignored
    else if (*format == 'X') #O if - or . O ignored
    else if (*format == '%')

    quid '-' flag ??
*/
    while (*(++format))
    {
        if (*format == '-' ||*format == 'O' || *format == ' ' 
        || *format == '#' || *format == '+')
            ret++;
        // else if *format == '.' ! order: flags precision
    }
    printf("count = %d\n", ret);
    return (ret);
}

int ft_printf(const char *format, ...)
{
    va_list ptr;
    int     ret;
    int     i;
     
    va_start(ptr, format);
    ret = 0;
    while (*format)
    {
        int i = 0;
        if (*format == '%')
        {
            i = check_format(format, ptr);
            format += i;
        }
        else
        {
            write(1, &(*format++), 1);
            ret++;
        }
    }
    va_end(ptr);
    return (ret);
}

int main()
{
    char *s = "123";
    printf("ret = %d\n", ft_printf("123%O-+ #.", s));
    return (0);
}