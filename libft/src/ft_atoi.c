/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:28:08 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:43:17 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow_long(long number, char next_digit, int negative)
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

static int	ft_get_output(const char *str, int negative)
{
	long int	output;

	output = 0;
	while (ft_isdigit(*str))
	{
		if (ft_check_overflow_long(output, *str, negative) < 0)
			return ((int)LONG_MIN);
		if (ft_check_overflow_long(output, *str, negative) > 0)
			return ((int)LONG_MAX);
		output = output * 10 + (*str - '0');
		str++;
	}
	return ((int)output);
}

int	ft_atoi(const char *nptr)
{
	int	negative;
	int	output;

	if (!nptr)
		return (0);
	negative = 0;
	output = 0;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		negative++;
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
// 	char *str = "     -2147483648";
// 	printf("%d\n",ft_atoi(str));
// 	printf("%d\n",atoi(str));
// }
