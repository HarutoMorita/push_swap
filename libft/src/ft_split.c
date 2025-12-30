/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:29:25 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/25 17:32:21 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_word_count(char const *str, char ch)
{
	size_t	counter;
	int		head;

	head = 1;
	counter = 0;
	while (*str)
	{
		if (head == 1 && *str != ch)
		{
			counter++;
			head = 0;
		}
		else if (head == 0 && *str == ch)
			head = 1;
		str++;
	}
	return (counter);
}

static char	*ft_strndup(char const *str, size_t len)
{
	size_t	index;
	char	*buffer;

	index = 0;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (index < len)
	{
		buffer[index] = str[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

static void	ft_freeall(char **strs)
{
	size_t	index;

	index = 0;
	while (strs[index])
	{
		free(strs[index]);
		index++;
	}
	free(strs);
}

static char	**ft_splitter(char **strs, size_t size, char const *str, char ch)
{
	size_t	index;
	size_t	len;
	char	*start;

	len = 0;
	index = 0;
	while (index < size)
	{
		while (*str == ch && *str != '\0')
			str++;
		len = 0;
		start = (char *)str;
		while (*str != ch && *str != '\0')
		{
			str++;
			len++;
		}
		strs[index] = ft_strndup(start, len);
		if (!strs[index])
			return (ft_freeall(strs), NULL);
		index++;
	}
	strs[index] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	if (size == 0)
	{
		strs[0] = NULL;
		return (strs);
	}
	strs = ft_splitter(strs, size, s, c);
	return (strs);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*str = "##abcd#efg##hijk###lmn###";
// 	char	sep = '#';
// 	int		index = 0;
// 	char	**strs = ft_split(str, sep);

// 	while(strs[index] != NULL)
// 	{
// 		printf("%s$\n", strs[index]);
// 		index++;
// 	}
// 	ft_freeall(strs, index);
// 	return (0);
// }
