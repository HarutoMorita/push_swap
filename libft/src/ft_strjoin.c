/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:33 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/13 17:30:31 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 > SIZE_MAX - len_s2)
		return (NULL);
	len_total = len_s1 + len_s2;
	new = (char *)malloc(sizeof(char) * (len_total + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, len_total + 1);
	return (new);
}

// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
// 	char const *s1 = "abcde";
// 	char const *s2 = "fghij";
// 	char *new;
// 	new = ft_strjoin(s1, s2);
// 	printf("%s + %s = %s\n", s1, s2, new);
// 	free(new);
// 	return (0);
// }
