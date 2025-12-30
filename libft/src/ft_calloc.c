/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:18:50 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/13 17:28:29 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*dest;
	size_t			total;

	if (nmemb == 0 || size == 0)
		return (ft_strdup(""));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	dest = malloc(total);
	if (!dest)
		return (NULL);
	ft_bzero(dest, total);
	return ((void *)dest);
}

// #include <stdio.h>
// #include <malloc.h>
// #include <string.h>
// int	main(void)
// {
// 	size_t n = 10;
// 	size_t s = 1;
// 	void	*expected = calloc(n, s);
// 	void	*actual = ft_calloc(n, s);
// 	if (!expected || !actual)
// 		printf("Error\n");
// 	if (malloc_usable_size(actual) != malloc_usable_size(expected))
// 		printf("Error\n");
// 	else
// 		printf("%p, %p\n", actual, expected);
// 	if (memcmp(actual, expected, n * s) != 0)
// 		printf("Error\n");
// 	else
// 		printf("%p, %p\n", actual, expected);
// 	free(actual);
// 	free(expected);
// 	return 0;
// }
