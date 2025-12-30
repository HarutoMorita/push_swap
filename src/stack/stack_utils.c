/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:07:10 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:43:16 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	get_max_rank(t_stack *stk)
{
	t_node	*temp;
	size_t	max;

	temp = stk->top;
	max = 0;
	while (temp)
	{
		if (max < temp->rank)
			max = temp->rank;
		temp = temp->next;
	}
	return (max);
}

size_t	get_min_rank(t_stack *stk)
{
	t_node	*temp;
	size_t	min;

	temp = stk->top;
	min = UINT_MAX;
	while (temp)
	{
		if (min > temp->rank)
			min = temp->rank;
		temp = temp->next;
	}
	return (min);
}

size_t	get_rank_index(t_stack *stk, int index)
{
	t_node	*temp;
	size_t	len;

	if (!stk || !stk->top)
		return (0);
	temp = stk->top;
	if (index < 0)
		len = stk->size + index;
	else
		len = (size_t)index;
	if (len >= stk->size)
		len = stk->size - 1;
	while (len > 0 && temp->next)
	{
		temp = temp->next;
		len--;
	}
	return (temp->rank);
}

void	renew_size(t_stack *stk)
{
	t_node	*temp;
	size_t	size;

	temp = stk->top;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	stk->size = size;
}

bool	is_sorted(t_stack *stk)
{
	t_node	*temp;
	int		curr_num;

	temp = stk->top;
	while (temp->next)
	{
		curr_num = temp->num;
		temp = temp->next;
		if (curr_num > temp->num)
			return (false);
	}
	return (true);
}
