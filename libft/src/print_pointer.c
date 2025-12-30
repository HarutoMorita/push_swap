/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:47:21 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/19 15:31:08 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	rec_print_ptr(uintptr_t num, int count)
{
	int		ret;
	char	*base;

	if (num == 0)
		return (count);
	base = "0123456789abcdef";
	count = rec_print_ptr(num / 16, count);
	ret = print_char(base[num % 16]);
	if (ret < 0)
		return (-1);
	count += ret;
	return (count);
}

int	print_pointer(void *ptr)
{
	uintptr_t	ptr_ui;
	int			count;

	if (!ptr)
		return (print_str("(nil)"));
	ptr_ui = (uintptr_t)ptr;
	count = print_str("0x");
	count = rec_print_ptr(ptr_ui, count);
	return (count);
}
