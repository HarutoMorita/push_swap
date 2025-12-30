/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:39 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:52:15 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (len);
	while (index < (size - 1) && *src)
	{
		dst[index] = *src;
		src++;
		index++;
	}
	dst[index] = '\0';
	return (len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int main (void)
// {
// 	unsigned int a = 0;
// 	unsigned int b = 0;
// 	char dest[16];
// 	char src[] = {"0123456789ABCDEF"};
// 	char dest2[16];
// 	a = ft_strlcpy(dest,src,16);
// 	printf("Len: %d\n", a);
// 	printf("Dest: %s\n", dest);
// 	b = strlcpy(dest2,src,16);
// 	printf("Len: %d\n", b);
// 	printf("Dest: %s\n", dest2);
// 	return (0);
// }
