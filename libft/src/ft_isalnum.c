/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:47:59 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/19 21:53:38 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	char A = 'A';
// 	char Z = 'Z';
// 	char a = 'a';
// 	char z = 'z';
// 	char zero = '0';
// 	char nine = '9';
// 	char nor = '*';
// 	printf("%d\n", ft_isalnum(A));
// 	printf("%d\n", ft_isalnum(Z));
// 	printf("%d\n", ft_isalnum(a));
// 	printf("%d\n", ft_isalnum(z));
// 	printf("%d\n", ft_isalnum(zero));
// 	printf("%d\n", ft_isalnum(nine));
// 	printf("%d\n", ft_isalnum(nor));
// 	printf("%d\n", ft_isalnum(0));
// 	printf("------\n");
// 	printf("%d\n", isalnum(A));
// 	printf("%d\n", isalnum(Z));
// 	printf("%d\n", isalnum(a));
// 	printf("%d\n", isalnum(z));
// 	printf("%d\n", isalnum(zero));
// 	printf("%d\n", isalnum(nine));
// 	printf("%d\n", isalnum(nor));
// 	printf("%d\n", isalnum(0));
// 	return(0);
// }
