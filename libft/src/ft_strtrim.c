/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:55 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/13 17:30:48 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinstr(char const c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	head;
	size_t	tail;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	head = 0;
	tail = ft_strlen(s1);
	while (ft_isinstr(s1[head], set))
		head++;
	if (tail > 0)
		tail--;
	while (ft_isinstr(s1[tail], set) && (head < tail))
		tail--;
	len = tail - head + 1;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	s1 += head;
	ft_strlcpy(copy, s1, len + 1);
	return (copy);
}

// #include <stdio.h>
// int main (void)
// {
// 	char *trimed = ft_strtrim("tripouille   xxx", " x");
// 	printf("%s$\n", trimed);
// 	free(trimed);
// 	return (0);
// }
