/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:24:45 by cwastche          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:52 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hex(va_list args, char c)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	if (c == 'x')
		return (ft_putnbr_base(arg, "0123456789abcdef", 16, c));
	return (ft_putnbr_base(arg, "0123456789ABCDEF", 16, c));
}

size_t	ft_strlen(const char *s)
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
		return (write(1, "-2147483648", 11));
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
