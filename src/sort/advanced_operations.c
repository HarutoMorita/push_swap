/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:05:24 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:45:38 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	move_to_top(t_stack *stk, int len, t_mode mode)
{
	size_t	op_count;

	op_count = 0;
	if (len >= 0)
	{
		while (len-- > 0)
			op_count += op_rotate(stk, mode);
	}
	else
	{
		while (len++ < 0)
			op_count += op_rotate_reverse(stk, mode);
	}
	return (op_count);
}

size_t	push_target(t_stack *dest, t_stack *src, t_mode p_mode, size_t trgt)
{
	int		len;
	size_t	op_count;
	t_mode	r_mode;

	if (!src || src->size == 0)
		return (0);
	if (p_mode > AW)
		r_mode = p_mode - B;
	else
		r_mode = p_mode + B;
	op_count = 0;
	len = len_to_target(src, trgt);
	op_count += move_to_top(src, len, r_mode);
	op_count += op_push(dest, src, p_mode);
	return (op_count);
}

static bool	is_in_stack(t_stack *stk, size_t rank)
{
	t_node	*node;

	node = stk->top;
	while (node)
	{
		if (node->rank == rank)
			return (true);
		node = node->next;
	}
	return (false);
}

static bool	is_next_max_closer(t_stack *stk_b, size_t max)
{
	int	len_max;
	int	len_next_max;

	if (stk_b->size < 2 || max == 0)
		return (0);
	if (!is_in_stack(stk_b, max - 1))
		return (false);
	len_max = len_to_target(stk_b, max);
	len_next_max = len_to_target(stk_b, max - 1);
	if (len_max < 0)
		len_max = len_max * -1;
	if (len_next_max < 0)
		len_next_max = len_next_max * -1;
	if (len_next_max + 1 < len_max)
		return (true);
	return (false);
}

size_t	push_back(t_stack *stk_a, t_stack *stk_b, bool out)
{
	size_t	op_count;
	size_t	max;

	op_count = 0;
	while (stk_b->size > 0)
	{
		max = get_max_rank(stk_b);
		if (is_next_max_closer(stk_b, max))
		{
			op_count += push_target(stk_a, stk_b, out_check(A, out), max - 1);
			op_count += push_target(stk_a, stk_b, out_check(A, out), max);
			op_count += op_swap(stk_a, out_check(A, out));
		}
		else
			op_count += push_target(stk_a, stk_b, out_check(A, out), max);
	}
	return (op_count);
}
