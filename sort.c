/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:34:28 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:43:24 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selection_sort(int *arr, size_t len)
{
	size_t	min_pos;
	size_t	index;
	size_t	done;
	int		temp;

	done = 0;
	while (done < len - 1)
	{
		min_pos = done;
		index = done + 1;
		while (index < len)
		{
			if (arr[min_pos] > arr[index])
				min_pos = index;
			index++;
		}
		if (min_pos != done)
		{
			temp = arr[done];
			arr[done] = arr[min_pos];
			arr[min_pos] = temp;
		}
		done++;
	}
}

static void	add_rank(t_stack *stk, int *nums, size_t len)
{
	t_node	*curr;
	size_t	index;

	curr = stk->top;
	while (curr)
	{
		index = 0;
		while (index < len)
		{
			if (curr->num == nums[index])
			{
				curr->rank = index;
				break ;
			}
			index++;
		}
		curr = curr->next;
	}
}

static bool	rank_nodes(t_stack *stk)
{
	int		*nums;
	t_node	*curr;
	size_t	index;

	curr = stk->top;
	index = 0;
	nums = malloc(sizeof(int) * stk->size);
	if (!nums)
		return (false);
	while (curr)
	{
		nums[index] = curr->num;
		curr = curr->next;
		index++;
	}
	selection_sort(nums, index);
	add_rank(stk, nums, index);
	free(nums);
	return (true);
}

bool	sort_stack(t_stack *stk_a)
{
	t_stack	*stk_b;
	bool	no_error;

	no_error = true;
	if (!rank_nodes(stk_a))
		return (false);
	if (stk_a->size == 1 || is_sorted(stk_a))
		return (true);
	if (stk_a->size == 2)
		op_swap(stk_a, AW);
	else if (stk_a->size < 6)
		sort_small(stk_a, true);
	else
	{
		stk_b = stack_init();
		if (!stk_b)
			return (false);
		no_error = sort_init(stk_a, stk_b);
		free_stack(&stk_b);
	}
	if (!no_error)
		return (false);
	return (true);
}
