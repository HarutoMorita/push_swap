/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:07 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:49:15 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_cpy_backward(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	while (n > 0)
	{
		dest_cast[n - 1] = src_cast[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src || n == 0)
		return (NULL);
	if (dest > src)
		ft_cpy_backward(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
// 	char str[16] = "123456789ABCDEF";
// 	char *adr;
// 	char *src = &str[0];
// 	char *dest = &str[4];
// 	//int size = strlen(str);

// 	adr = ft_memmove(dest, src, 30);
// 	printf("mem: %s addr: %p\n", dest, adr);
// 	// adr = memmove(dest, src, 30);
// 	// printf("mem: %s addr: %p\n", dest, adr);
// 	return 0;
// }
