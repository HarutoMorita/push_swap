/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:16:37 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/21 13:55:49 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	printf("%d\n", ft_isprint(0));
// 	printf("%d\n", ft_isprint(31));
// 	printf("%d\n", ft_isprint(32));
// 	printf("%d\n", ft_isprint(126));
// 	printf("%d\n", ft_isprint(127));
// 	printf("------\n");
// 	printf("%d\n", isprint(0));
// 	printf("%d\n", isprint(31));
// 	printf("%d\n", isprint(32));
// 	printf("%d\n", isprint(126));
// 	printf("%d\n", isprint(127));
// 	return(0);
// }
