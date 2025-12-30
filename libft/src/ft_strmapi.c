/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:42 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/13 17:30:40 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*new;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new[index] = f(index, s[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}

// #include <ctype.h>
// #include <stdio.h>
// static int (*f)(int) = NULL;
// static char F(unsigned int i, char c) { (void)i; return (f(c)); };
// int	main(void)
// {
// 	char	*str;
// 	f = toupper;
// 	str = ft_strmapi("abcdef", F);
// 	printf("%s$\n",str);
// 	free(str);
// 	str = ft_strmapi("aBcDeF", F);
// 	printf("%s$\n",str);
// 	free(str);
// 	str = ft_strmapi("123456", F);
// 	printf("%s$\n",str);
// 	free(str);
// 	f = tolower;
// 	str = ft_strmapi("ABCDEF", F);
// 	printf("%s$\n",str);
// 	free(str);
// 	str = ft_strmapi("aBcDeF", F);
// 	printf("%s$\n",str);
// 	free(str);
// 	str = ft_strmapi("123456", F);
// 	printf("%s$\n",str);
// 	free(str);
// 	return (0);
// }
