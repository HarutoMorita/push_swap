/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:21:05 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/21 13:54:40 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
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
// 	char not_alp = '8';
// 	printf("%d\n", ft_isalpha(A));
// 	printf("%d\n", ft_isalpha(Z));
// 	printf("%d\n", ft_isalpha(a));
// 	printf("%d\n", ft_isalpha(z));
// 	printf("%d\n", ft_isalpha(not_alp));
// 	printf("%d\n", ft_isalpha(0));
// 	printf("------\n");
// 	printf("%d\n", isalpha(A));
// 	printf("%d\n", isalpha(Z));
// 	printf("%d\n", isalpha(a));
// 	printf("%d\n", isalpha(z));
// 	printf("%d\n", isalpha(not_alp));
// 	printf("%d\n", isalpha(0));
// 	return(0);
// }
