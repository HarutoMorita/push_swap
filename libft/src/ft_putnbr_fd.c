/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:19 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/22 14:15:24 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_str_tab(char *tab, int size)
{
	size_t	index;
	char	temp;
	size_t	half_size;

	temp = 0;
	index = 0;
	half_size = size / 2;
	while (index < half_size)
	{
		temp = tab[index];
		tab[index] = tab[size - index -1];
		tab[size - index - 1] = temp;
		index++;
	}
}

static void	ft_itostr_out(int n, int fd)
{
	char	*dec;
	char	str[11];
	size_t	index;

	index = 0;
	dec = "0123456789";
	while (n != 0)
	{
		str[index] = dec[n % 10];
		n /= 10;
		index++;
	}
	str[index] = '\0';
	ft_rev_str_tab(str, index);
	ft_putstr_fd(str, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	ft_itostr_out(n, fd);
}

// #include <limits.h>
// int	main(void)
// {
// 	int n = INT_MIN;
// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }
