/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:28 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:50:56 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_char;

	if (!s)
		return (NULL);
	c_char = (char)c;
	while (*s)
	{
		if (*s == c_char)
			return ((char *)s);
		s++;
	}
	if (c_char == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char	str[] = "abcde";
// 	int		c = 97;
// 	char	*ans;
// 	ans = ft_strchr(str, c);
// 	printf("%p\n", ans);
// 	ans = strchr(str, c);
// 	printf("%p\n", ans);
// 	return(0);
// }
