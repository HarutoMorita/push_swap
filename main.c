/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:40:57 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:45:14 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	stack_set(t_stack *stk, size_t size, char **nums)
{
	size_t	index;
	int		*arr;
	long	num;

	if (!stk || size == 0 || !arg_check(nums, size))
		return (false);
	arr = malloc(sizeof(int) * (size));
	if (!arr)
		return (false);
	index = 0;
	while (index < size)
	{
		num = ft_atol(nums[size - 1 - index]);
		if (num > INT_MAX || num < INT_MIN)
			return (free(arr), false);
		if (!dup_check(arr, (int)num, index))
			return (free(arr), false);
		arr[index++] = (int)num;
		push_new(stk, (int)num);
	}
	stk->size = size;
	free(arr);
	return (true);
}

static void	free_all(t_stack **stk, char **strs, bool is_split)
{
	if (is_split)
		free_split(strs);
	if (stk || *stk)
		free_stack(stk);
}

static	int	error_handle(t_stack **stk, char **strs, bool is_split)
{
	write(2, "Error\n", 6);
	free_all(stk, strs, is_split);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	**nums;
	bool	is_split;
	bool	no_error;

	is_split = false;
	no_error = true;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		is_split = true;
	}
	else
		nums = &argv[1];
	stack = stack_init();
	if (!stack || !nums || !stack_set(stack, count_strings(nums), nums))
		return (error_handle(&stack, nums, is_split));
	else
		no_error = sort_stack(stack);
	if (!no_error)
		return (error_handle(&stack, nums, is_split));
	free_all(&stack, nums, is_split);
	return (0);
}
