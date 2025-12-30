/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:31 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/13 17:30:25 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

// #include <ctype.h>
// #include <stdio.h>
// static int (*f)(int) = NULL;
// static void F(unsigned int i, char *s) { (void)i; *s = f(*s); };
// int	main(void)
// {
// 	f = toupper;
// 	char str[] = "abcdef";
// 	char str2[] = "aBcDeF";
// 	ft_striteri(str, F);
// 	printf("%s$\n",str);
// 	ft_striteri(str2, F);
// 	printf("%s$\n",str2);
// 	f = tolower;
// 	char str3[] = "ABCDEF";
// 	char str4[] = "aBcDeF";
// 	ft_striteri(str3, F);
// 	printf("%s$\n",str3);
// 	ft_striteri(str4, F);
// 	printf("%s$\n",str4);
// 	return (0);
// }
