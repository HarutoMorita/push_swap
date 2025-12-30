/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:20:04 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:51:13 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	index;
	size_t	len;

	if (!s)
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (index < len)
	{
		dest[index] = s[index];
		index++;
	}
	dest[len] = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char *str = "0123456789";
// 	char *new = ft_strdup(str);
// 	char *new2 = strdup(str);
// 	if (new)
// 		printf("%s\n", new);
// 	if (new2)
// 		printf("%s\n", new2);
// 	free(new2);
// 	free(new);
// 	return 0;
// }
