/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:10 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:49:41 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_cast;

	if (!s || n == 0)
		return (NULL);
	index = 0;
	s_cast = (unsigned char *)s;
	while (index < n)
	{
		s_cast[index] = c;
		index++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
// 	// char str[10];
// 	// char *adr;
// 	// int size = sizeof(str);
// 	// adr = ft_memset(str, 'a', size);
// 	// printf("mem: %s addr: %p\n", str, adr);
// 	// adr = memset(str, 'z', size);
// 	// printf("mem: %s addr: %p\n", str, adr);
// 	int arr[5];
// 	int size = sizeof(arr);
// 	int *adr;
// 	adr = memset(arr, 384, size);
// 	printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
// 	adr = ft_memset(arr, 384, size);
// 	printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
// 	return 0;
// }
