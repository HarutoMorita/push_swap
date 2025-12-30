/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:49 by hmorita           #+#    #+#             */
/*   Updated: 2025/10/21 13:46:58 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	index;

	little_len = 0;
	index = 0;
	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	if (len < little_len || !*big)
		return (NULL);
	while (index <= len - little_len)
	{
		if (ft_strncmp(&big[index], little, little_len) == 0)
			return ((char *)&big[index]);
		index++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char	str1[] = "aaabcabcd";
// 	char	str2[] = "aabc";
// 	//char * empty = (char*)"";
// 	char	*ans;
// 	ans = strnstr(str1, str2, 5);
// 	printf("%p\n", ans);
// 	ans = ft_strnstr(str1, str2, 5);
// 	printf("%p\n", ans);
// 	return (0);
// }
