/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:23:53 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/19 15:32:52 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	rec_print_hex(unsigned int num, int count, char *base)
{
	int	ret;

	if (num == 0)
		return (count);
	count = rec_print_hex(num / 16, count, base);
	ret = print_char(base[num % 16]);
	if (ret < 0)
		return (-1);
	count += ret;
	return (count);
}

int	print_hexadecimal(unsigned int num, char format)
{
	int		count;
	char	*base;

	if (num == 0)
	{
		count = write(1, "0", 1);
		return (count);
	}
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		return (-1);
	count = 0;
	count = rec_print_hex(num, count, base);
	return (count);
}
