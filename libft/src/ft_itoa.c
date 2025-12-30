/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:28:20 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 21:55:11 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_str_bytes(unsigned int n, int negative)
{
	size_t	count;

	count = 0;
	if (negative)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_itostr(unsigned int n, int negative)
{
	char	*base;
	char	*str;
	size_t	size;

	size = ft_get_str_bytes(n, negative) + 1;
	base = "0123456789";
	str = (char *)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	size--;
	str[size] = '\0';
	while (n > 0)
	{
		size--;
		str[size] = base[n % 10];
		n /= 10;
	}
	if (negative)
	{
		size--;
		str[size] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = n * -1;
		negative = 1;
	}
	str = ft_itostr(n, negative);
	return (str);
}

// #include <stdio.h>
// int main (void)
// {
// 	int num = INT_MAX;
// 	char *str = ft_itoa(num);
// 	printf("int: %d, str: %s\n", num, str);
// 	free(str);
// 	return (0);
// }
