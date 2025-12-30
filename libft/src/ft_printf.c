/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:44:19 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/19 15:29:49 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print_arg(va_list args, const char format)
{
	if (format == 's')
		return (print_str(va_arg(args, char *)));
	else if (format == 'c')
		return (print_char(va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hexadecimal(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (format == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		write_bytes;
	size_t	index;
	size_t	len;

	index = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
			write_bytes = print_arg(args, str[++index]);
		else
			write_bytes = print_char(str[index]);
		if (write_bytes < 0)
			return (-1);
		len += write_bytes;
		index++;
	}
	return (len);
}
