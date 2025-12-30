/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:04 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:48:43 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	if (!dest || !src || n == 0)
		return (NULL);
	index = 0;
	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	while (index < n)
	{
		dest_cast[index] = src_cast[index];
		index++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
// 	char str[10] = "a";
// 	char *str2 = "1234567890";
// 	char *adr;
// 	int size = strlen(str2);
// 	adr = ft_memcpy(str, str2, size);
// 	printf("mem: %s addr: %p\n", str, adr);
// 	bzero(str, size);
// 	printf("mem: %s addr: %p\n", str, adr);
// 	adr = memcpy(str, str2, size);
// 	printf("mem: %s addr: %p\n", str, adr);
// 	return 0;
// }
