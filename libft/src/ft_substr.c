/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:59 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:54:21 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *str, size_t len)
{
	size_t	index;
	char	*buffer;

	if (!str)
		return (0);
	index = 0;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (index < len && str[index])
	{
		buffer[index] = str[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len > (len_s - start))
		len = len_s - start;
	if (start > len_s - 1)
		len = 0;
	if (len == 0)
		return (ft_strdup(""));
	s += start;
	sub = ft_strndup(s, len);
	if (!sub)
		return (NULL);
	return (sub);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char const *str = "0123456789";
// 	char *subs;

// 	subs = ft_substr(str, 100, 1);
// 	printf("%s\n",subs);
// 	free(subs);
// 	return (0);
// }
