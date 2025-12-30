/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:27:30 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:43:36 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sort_case3(t_stack *stk_a, bool out)
{
	t_node	*mid;
	size_t	max;
	size_t	op_count;
	t_mode	mode;

	mode = out_check(A, out);
	op_count = 0;
	max = get_max_rank(stk_a);
	mid = stk_a->top->next;
	if (stk_a->top->rank == max)
		op_count += op_rotate(stk_a, mode);
	else if (mid->rank == max)
		op_count += op_rotate_reverse(stk_a, mode);
	if (is_sorted(stk_a) == false)
		op_count += op_swap(stk_a, mode);
	return (op_count);
}

size_t	sort_small(t_stack *stk_a, bool out)
{
	t_stack	*stk_b;
	size_t	op_count;
	t_mode	mode;

	mode = out_check(B, out);
	stk_b = stack_init();
	op_count = 0;
	while (stk_a->size > 3)
		op_count += push_target(stk_b, stk_a, mode, get_min_rank(stk_a));
	op_count += sort_case3(stk_a, out);
	mode = out_check(A, out);
	if (stk_b->size == 1)
		op_count += op_push(stk_a, stk_b, mode);
	else if (stk_b->size == 2)
	{
		op_count += op_push(stk_a, stk_b, mode);
		op_count += op_push(stk_a, stk_b, mode);
		if (stk_a->top->rank > stk_a->top->next->rank)
			op_count += op_swap(stk_a, out_check(A, out));
	}
	free_stack(&stk_b);
	return (op_count);
}
