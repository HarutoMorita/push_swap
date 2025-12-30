/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:46:11 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:43:32 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_square_root(size_t num)
{
	size_t	res;

	res = 1;
	if (num == 0)
		return (0);
	else if (num == 1)
		return (1);
	while (res * res <= num)
		res++;
	return (res - 1);
}

size_t	len_to_highest(t_stack *stk, size_t min, size_t max)
{
	t_node	*node;
	size_t	len;

	len = 0;
	node = stk->top;
	while (node)
	{
		if (node->rank >= min && node->rank <= max)
			return (len);
		len++;
		node = node->next;
	}
	return (len);
}

size_t	len_to_lowest(t_stack *stk, size_t min, size_t max)
{
	t_node	*node;
	size_t	ret;
	size_t	len;

	len = 0;
	ret = 0;
	node = stk->top;
	while (node)
	{
		if (node->rank >= min && node->rank <= max)
			ret = len;
		len++;
		node = node->next;
	}
	return (ret);
}

int	len_to_best_target(t_stack *stk, size_t min, size_t max)
{
	size_t	to_lowest;
	size_t	to_highest;
	size_t	counter;

	counter = 0;
	to_highest = len_to_highest(stk, min, max);
	if (to_highest == stk->size)
		return ((int)to_highest);
	to_lowest = stk->size - len_to_lowest(stk, min, max);
	if (to_highest > to_lowest)
		return ((int)(to_lowest * -1));
	else
		return ((int)to_highest);
}

int	len_to_target(t_stack *stk, size_t trgt)
{
	t_node	*node;
	int		len;

	len = 0;
	node = stk->top;
	while (node)
	{
		if (node->rank == trgt)
			break ;
		len++;
		node = node->next;
	}
	if (node == NULL)
		return (INT_MAX);
	if (len > (int)(stk->size / 2))
		len = len - (int)stk->size;
	return (len);
}
