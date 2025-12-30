/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 01:34:54 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:45:33 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **strs)
{
	size_t	index;

	if (!strs)
		return ;
	index = 0;
	while (strs[index])
	{
		free(strs[index]);
		strs[index] = NULL;
		index++;
	}
	free(strs);
}

size_t	count_strings(char **strs)
{
	size_t	index;

	index = 0;
	while (strs && strs[index])
		index++;
	return (index);
}

bool	dup_check(int *arr, int num, size_t len)
{
	size_t	index1;

	index1 = 0;
	while (index1 < len)
	{
		if (arr[index1] == num)
			return (false);
		index1++;
	}
	return (true);
}

bool	arg_check(char **arg, size_t size)
{
	size_t	idx_str;
	size_t	idx_arg;

	if (!arg)
		return (false);
	idx_arg = 0;
	while (idx_arg < size)
	{
		idx_str = 0;
		if (arg[idx_arg][idx_str] == '\0')
			return (false);
		if (arg[idx_arg][idx_str] == '-' || arg[idx_arg][idx_str] == '+' )
			idx_str++;
		if (arg[idx_arg][idx_str] == '\0')
			return (false);
		while (arg[idx_arg][idx_str])
		{
			if (ft_isdigit(arg[idx_arg][idx_str]) == 0)
				return (false);
			idx_str++;
		}
		idx_arg++;
	}
	return (true);
}
