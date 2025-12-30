/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:59:46 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/22 19:34:14 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_update(t_chunk *chunk)
{
	chunk->min += chunk->size;
	chunk->max += chunk->size;
	chunk->median = (chunk->min + chunk->max) / 2;
	chunk->counter = 0;
}

void	chunk_reset(t_chunk *chunk, size_t size)
{
	chunk->size = size;
	chunk->min = 0;
	chunk->max = size - 1;
	chunk->median = (chunk->min + chunk->max) / 2;
	chunk->counter = 0;
}

t_chunk	*chunk_init(size_t size)
{
	t_chunk	*new;

	new = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new)
		return (NULL);
	new->size = size;
	new->min = 0;
	new->max = size - 1;
	new->median = (new->min + new->max) / 2;
	new->counter = 0;
	return (new);
}
