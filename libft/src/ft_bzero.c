/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:28:11 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:44:09 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (s)
		ft_memset(s, '\0', n);
}

// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
// 	char str[10];
// 	int size = sizeof(str);
// 	ft_memset(str, 'a', size);
// 	printf("mem: %s\n", str);
// 	ft_bzero(str, size);
// 	printf("mem: %s\n", str);
// 	memset(str, 'z', size);
// 	printf("mem: %s\n", str);
// 	bzero(str, size);
// 	printf("mem: %s\n", str);
// 	return 0;
// }
