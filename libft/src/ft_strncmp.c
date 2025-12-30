/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:46 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/18 16:53:12 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
		if (*s1_cast == '\0' || *s2_cast == '\0')
			break ;
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
// 	char	s2[] = "ab";
// 	printf ("%s - %s = %d\n",s1, s2, strncmp(s1, s2, 2));
// 	printf ("%s - %s = %d\n",s1, s2, ft_strncmp(s1, s2, 2));

// 	return (0);
// }
