/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:21:39 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/19 15:31:34 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	rec_print_ui(unsigned int num, int count)
{
	int		ret;
	char	*base;

	if (num == 0)
		return (count);
	base = "0123456789";
	count = rec_print_ui(num / 10, count);
	ret = print_char(base[num % 10]);
	if (ret < 0)
		return (-1);
	count += ret;
	return (count);
}

int	print_unsigned_int(unsigned int num)
{
	int		count;

	if (num == 0)
	{
		count = write(1, "0", 1);
		return (count);
	}
	count = 0;
	count = rec_print_ui(num, count);
	return (count);
}
