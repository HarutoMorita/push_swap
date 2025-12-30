/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:49:06 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/09 17:49:06 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	op_swap(t_stack *stk, t_mode mode)
{
	t_node	*first;
	t_node	*second;

	if (!stk || !stk->top || stk->size <= 1)
		return (0);
	first = stk->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stk->top = second;
	if (mode == AW)
		write(1, "sa\n", 3);
	else if (mode == BW)
		write(1, "sb\n", 3);
	return (1);
}

size_t	op_push(t_stack *dest, t_stack *src, t_mode mode)
{
	t_node	*to_push;

	if (!src || !src->top || dest == src)
		return (0);
	to_push = src->top;
	src->top = to_push->next;
	to_push->next = dest->top;
	dest->top = to_push;
	if (mode == AW)
		write(1, "pa\n", 3);
	else if (mode == BW)
		write(1, "pb\n", 3);
	renew_size(dest);
	renew_size(src);
	return (1);
}

size_t	op_rotate(t_stack *stk, t_mode mode)
{
	t_node	*first;
	t_node	*last;

	if (!stk || !stk->top || stk->size <= 1)
		return (0);
	first = stk->top;
	last = stk->top;
	while (last->next != NULL)
		last = last->next;
	stk->top = first->next;
	last->next = first;
	first->next = NULL;
	if (mode == AW)
		write(1, "ra\n", 3);
	else if (mode == BW)
		write(1, "rb\n", 3);
	return (1);
}

size_t	op_rotate_reverse(t_stack *stk, t_mode mode)
{
	t_node	*curr_last;
	t_node	*new_last;

	if (!stk || !stk->top || stk->size <= 1)
		return (0);
	new_last = stk->top;
	curr_last = new_last->next;
	while (curr_last->next != NULL)
	{
		new_last = curr_last;
		curr_last = curr_last->next;
	}
	curr_last->next = stk->top;
	stk->top = curr_last;
	new_last->next = NULL;
	if (mode == AW)
		write(1, "rra\n", 4);
	else if (mode == BW)
		write(1, "rrb\n", 4);
	return (1);
}

size_t	op_both(t_stack *stk_a, t_stack *stk_b, t_op_func op, t_mode mode)
{
	if (stk_a == stk_b)
		return (0);
	op(stk_a, mode);
	op(stk_b, mode);
	return (1);
}
