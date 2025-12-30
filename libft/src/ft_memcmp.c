/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:01 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:45:50 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while ((*s1_cast == *s2_cast) && (n - 1 > 0))
	{
		s1_cast++;
		s2_cast++;
		n--;
	}
	return ((int)(*s1_cast - *s2_cast));
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	s1[] = "abcdefg";
// 	char	s2[] = "abcdE";
// 	printf ("%d\n",ft_memcmp(s1, s2, 5));
// 	printf ("%d\n",memcmp(s1, s2, 5));
// 	return (0);
// }
