/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:39:25 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/21 13:54:55 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	char zero = '0';
// 	char nine = '9';
// 	char not_dig = '*';
// 	printf("%d\n", ft_isdigit(zero));
// 	printf("%d\n", ft_isdigit(nine));
// 	printf("%d\n", ft_isdigit(not_dig));
// 	printf("%d\n", ft_isdigit(0));
// 	printf("------\n");
// 	printf("%d\n", isdigit(zero));
// 	printf("%d\n", isdigit(nine));
// 	printf("%d\n", isdigit(not_dig));
// 	printf("%d\n", isdigit(0));
// 	return(0);
// }
