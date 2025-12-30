/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:28:57 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:45:04 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	size_t			index;

	if (!s)
		return (NULL);
	s_cast = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (s_cast[index] == (unsigned char)c)
			return ((void *)(s_cast + index));
		index++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
// 	size_t size = 30;
// 	char *addr;
// 	int c = 'A';
// 	char *s = calloc(30, sizeof(char));

// 	memcpy(s, "0123456789ABCDEF", 17);
// 	memcpy(s + 20, "abcde", 5);

// 	addr = memchr(s, c, size);
// 	printf("%s at %p\n", addr, addr);
// 	addr = ft_memchr(s, c, size);
// 	printf("%s at %p\n", addr, addr);
// 	return (0);
// }
