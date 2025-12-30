/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:48:19 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/09 17:48:19 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_stack(t_stack **stk_p)
{
	t_node	*curr;
	t_node	*next;

	if (!stk_p || !*stk_p)
		return ;
	curr = (*stk_p)->top;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(*stk_p);
	*stk_p = NULL;
}

t_node	*create_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = num;
	new->rank = 0;
	new->next = NULL;
	return (new);
}

void	push_new(t_stack *stk, int num)
{
	t_node	*new;

	if (!stk)
		return ;
	new = create_node(num);
	if (!new)
		return ;
	new->next = stk->top;
	stk->top = new;
}

t_stack	*stack_init(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->size = 0;
	new->top = NULL;
	return (new);
}
