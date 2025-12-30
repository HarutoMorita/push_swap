/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:28:08 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/25 19:45:41 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow_long(long number, char next_digit, bool negative)
{
	if (negative)
	{
		if (number == LONG_MAX / 10)
		{
			if (next_digit == '9')
				return (-1);
		}
		else if (number > LONG_MAX / 10)
			return (-1);
	}
	else
	{
		if (number == LONG_MAX / 10)
		{
			if (next_digit == '8' || next_digit == '9')
				return (1);
		}
		else if (number > LONG_MAX / 10)
			return (1);
	}
	return (0);
}

static long	ft_get_output(const char *str, bool negative)
{
	long	output;

	output = 0;
	while (ft_isdigit(*str))
	{
		if (ft_check_overflow_long(output, *str, negative) < 0)
			return (LONG_MIN);
		if (ft_check_overflow_long(output, *str, negative) > 0)
			return (LONG_MAX);
		output = output * 10 + (*str - '0');
		str++;
	}
	return (output);
}

long	ft_atol(const char *nptr)
{
	bool	negative;
	long	output;

	if (!nptr)
		return (0);
	negative = false;
	output = 0;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		negative = true;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	output = ft_get_output(nptr, negative);
	if (negative)
		output = output * -1;
	return (output);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
// 	char *str = "     -9223372036854775808";
// 	printf("%d\n",ft_atol(str));
// 	printf("%d\n",atol(str));
// }
