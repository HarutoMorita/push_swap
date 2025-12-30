/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:52 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:53:54 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	c_char;

	if (!s)
		return (NULL);
	c_char = (char)c;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		if (s[len - 1] == c_char)
			return ((char *)(s + len -1));
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	const char	str[] = "abcde";
// 	int	c = 0;
// 	char	*ans;
// 	ans = ft_strrchr(str, c);
// 	printf("%p\n", ans);
// 	ans = strrchr(str, c);
// 	printf("%p\n", ans);
// 	return(0);
// }
