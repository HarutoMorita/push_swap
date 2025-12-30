/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:36 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:52:20 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	cat_len = size - dst_len - 1;
	dst += dst_len;
	if (dst_len < size)
	{
		while (*src != '\0' && cat_len > 0)
		{
			*dst++ = *src++;
			cat_len--;
		}
		*dst = '\0';
		return (dst_len + src_len);
	}
	else
		return (size + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	s1[] = "abcdefg";
// 	char	s2[] = "hijklmn";
// 	char	s3[] = "abcdefg";
// 	int a;
// 	printf ("Before: %s\n",s1);
// 	a = strlcat(s1, s2, 10);
// 	printf ("After: %s, Length: %d\n",s1 ,a);
// 	printf ("Before: %s\n",s3);
// 	a = ft_strlcat(s3, s2, 10);
// 	printf ("After: %s, Length: %d\n",s3 ,a);

// 	return (0);
// }
