/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:08:46 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:45:19 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	push_within_chunk(
	t_stack *stk_a, t_stack *stk_b, t_chunk *chunk, bool out)
{
	int		len;
	size_t	op_count;
	size_t	safe_max;
	size_t	limit;

	limit = stk_a->size + stk_b->size - 4;
	if (chunk->max > limit)
		safe_max = limit;
	else
		safe_max = chunk->max;
	if (len_to_highest(stk_a, chunk->min, safe_max) == stk_a->size)
		return (0);
	len = len_to_best_target(stk_a, chunk->min, safe_max);
	op_count = move_to_top(stk_a, len, out_check(A, out));
	op_count += op_push(stk_b, stk_a, out_check(B, out));
	if (stk_b->top->rank < chunk->median)
		op_count += op_rotate(stk_b, out_check(B, out));
	return (op_count);
}

static size_t	chunk_sort(
	t_stack *stk_a, t_stack *stk_b, t_chunk *chunk, bool out)
{
	size_t	op_count;
	size_t	push_op;

	op_count = 0;
	while (stk_a->size > 3)
	{
		push_op = push_within_chunk(stk_a, stk_b, chunk, out);
		if (push_op == 0 || chunk->counter == chunk->size)
		{
			if (chunk->min >= stk_a->size + stk_b->size)
				break ;
			chunk_update(chunk);
			if (push_op == 0)
				continue ;
		}
		op_count += push_op;
		chunk->counter++;
	}
	op_count += sort_case3(stk_a, out);
	op_count += push_back(stk_a, stk_b, out);
	return (op_count);
}

static bool	chunk_optimize(t_stack *stk_a, t_stack *stk_b, t_chunk *chunk)
{
	size_t	min_op;
	size_t	curr_op;
	size_t	best_size;
	t_stack	*copy_a;
	size_t	max_size;

	min_op = SIZE_MAX;
	max_size = chunk->size * 3;
	while (chunk->size < max_size)
	{
		copy_a = copy_stack(stk_a);
		if (!copy_a)
			return (false);
		curr_op = chunk_sort(copy_a, stk_b, chunk, false);
		if (min_op > curr_op)
		{
			min_op = curr_op;
			best_size = chunk->size;
		}
		chunk->size++;
		chunk_reset(chunk, chunk->size);
		free_stack(&copy_a);
	}
	chunk_reset(chunk, best_size);
	return (true);
}

bool	sort_init(t_stack *stk_a, t_stack *stk_b)
{
	t_chunk	*chunk;

	chunk = chunk_init(get_square_root(stk_a->size));
	if (!chunk)
		return (false);
	if (!chunk_optimize(stk_a, stk_b, chunk))
		return (false);
	chunk_sort(stk_a, stk_b, chunk, true);
	free(chunk);
	if (!is_sorted(stk_a))
		return (false);
	return (true);
}
