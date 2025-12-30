/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 03:37:48 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/30 16:34:24 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	execute_operation(t_stack *stk_a, t_stack *stk_b, char *op)
{
	if (!op || op[0] == '\0')
		return (false);
	if (op[0] == 's')
		return (execute_swap(stk_a, stk_b, op));
	if (op[0] == 'p')
		return (execute_push(stk_a, stk_b, op));
	if (op[0] == 'r')
	{
		if (execute_rotate_reverse(stk_a, stk_b, op))
			return (true);
		return (execute_rotate(stk_a, stk_b, op));
	}
	return (false);
}

bool	execute_swap(t_stack *stk_a, t_stack *stk_b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		op_swap(stk_a, A);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		op_swap(stk_b, B);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		op_both(stk_a, stk_b, op_swap, AB);
	else
		return (false);
	return (true);
}

bool	execute_push(t_stack *stk_a, t_stack *stk_b, char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		op_push(stk_a, stk_b, A);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		op_push(stk_b, stk_a, B);
	else
		return (false);
	return (true);
}

bool	execute_rotate_reverse(t_stack *stk_a, t_stack *stk_b, char *op)
{
	if (ft_strncmp(op, "rra\n", 4) == 0)
		op_rotate_reverse(stk_a, A);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		op_rotate_reverse(stk_b, B);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		op_both(stk_a, stk_b, op_rotate_reverse, AB);
	else
		return (false);
	return (true);
}

bool	execute_rotate(t_stack *stk_a, t_stack *stk_b, char *op)
{
	if (ft_strncmp(op, "ra\n", 3) == 0)
		op_rotate(stk_a, A);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		op_rotate(stk_b, B);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		op_both(stk_a, stk_b, op_rotate, AB);
	else
		return (false);
	return (true);
}
