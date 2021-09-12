/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:24:22 by cwastche          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:26 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_base_int(int nb, char *base);
int		ft_putnbr_base(size_t nb, char *base, int base_len, char c);
int		ft_handle_char(va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_pointer(va_list args, char c);
int		ft_handle_int(va_list args);
int		ft_handle_uint(va_list args, char c);
int		ft_handle_hex(va_list args, char c);
int		ft_handle_hex_upper(va_list args, char c);
size_t	ft_strlen(const char *s);

#endif
