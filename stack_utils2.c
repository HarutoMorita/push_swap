/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:02:58 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:43:11 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*copy_nodes(t_node *src)
{
	t_node	*new;

	if (!src)
		return (NULL);
	new = create_node(src->num);
	if (!new)
		return (NULL);
	new->rank = src->rank;
	new->next = copy_nodes(src->next);
	return (new);
}

t_stack	*copy_stack(t_stack *src)
{
	t_stack	*dest;

	dest = stack_init();
	if (!dest)
		return (NULL);
	dest->top = copy_nodes(src->top);
	if (!(dest->top))
		return (NULL);
	dest->size = src->size;
	return (dest);
}

t_mode	out_check(t_mode mode, bool out)
{
	if (mode == A && out == true)
		return (AW);
	if (mode == B && out == true)
		return (BW);
	if (mode == A && out == false)
		return (A);
	if (mode == B && out == false)
		return (B);
	return (mode);
}
