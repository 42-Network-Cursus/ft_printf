/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:33:13 by cwastche          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:14 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char *spec, char c)
{
	while (*spec)
	{
		if (*spec == c)
			return (1);
		spec++;
	}
	return (0);
}

static int	ft_specifier(va_list args, char c)
{
	int	ret;

	ret = 0;
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
	else if (ft_check_format("x", c))
		ret += ft_handle_hex(args, 'x');
	else if (ft_check_format("X", c))
		ret += ft_handle_hex(args, 'X');
	else if (ft_check_format("%", c))
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

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
