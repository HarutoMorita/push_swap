/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:46:48 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/19 15:14:55 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_char(int ch)
{
	return (write(1, &ch, 1));
}

int	print_str(char *str)
{
	size_t	len;
	int		count;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	count = write(1, str, len);
	return (count);
}

int	print_int(int num)
{
	char	*str;
	int		count;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	count = print_str(str);
	free(str);
	return (count);
}
