/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 02:33:55 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/30 16:09:42 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	checker(t_stack *stk_a, t_stack *stk_b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (!execute_operation(stk_a, stk_b, input))
		{
			write(2, "Error\n", 6);
			free(input);
			get_next_line(-1);
			return (false);
		}
		free(input);
	}
	return (true);
}

static bool	checker_init(t_stack *stk_a)
{
	t_stack	*stk_b;
	bool	no_error;

	stk_b = stack_init();
	if (!stk_b)
		return (false);
	no_error = checker(stk_a, stk_b);
	if (!no_error)
		return (free_stack(&stk_b), false);
	if (is_sorted(stk_a) && stk_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stk_b);
	return (true);
}

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

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	**nums;
	bool	is_split;
	bool	result;

	is_split = false;
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
		result = checker_init(stack);
	if (!result)
		return (error_handle(&stack, nums, is_split));
	free_all(&stack, nums, is_split);
	return (0);
}
