/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:10:10 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/15 22:16:16 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	char A = 'A';
// 	char a = 'a';
// 	char zero = '0';
// 	char nine = '9';
// 	printf("%d\n", ft_isascii(A));
// 	printf("%d\n", ft_isascii(a));
// 	printf("%d\n", ft_isascii(zero));
// 	printf("%d\n", ft_isascii(nine));
// 	printf("%d\n", ft_isascii(0));
// 	printf("%d\n", ft_isascii(127));
// 	printf("%d\n", ft_isascii(128));
// 	printf("------\n");
// 	printf("%d\n", __isascii(A));
// 	printf("%d\n", __isascii(a));
// 	printf("%d\n", __isascii(zero));
// 	printf("%d\n", __isascii(nine));
// 	printf("%d\n", __isascii(0));
// 	printf("%d\n", __isascii(127));
// 	printf("%d\n", __isascii(128));
// 	return(0);
// }
