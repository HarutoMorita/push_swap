/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:41:10 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/28 15:46:56 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"

typedef struct s_chunk
{
	size_t	size;
	size_t	max;
	size_t	min;
	size_t	median;
	size_t	counter;
}	t_chunk;
bool	sort_stack(t_stack *stk);
size_t	sort_small(t_stack *stk_a, bool out);
size_t	sort_case3(t_stack *stk_a, bool out);
size_t	len_to_highest(t_stack *stk, size_t min, size_t max);
size_t	len_to_lowest(t_stack *stk, size_t min, size_t max);
int		len_to_best_target(t_stack *stk, size_t min, size_t max);
int		len_to_target(t_stack *stk, size_t trgt);
bool	sort_init(t_stack *stk_a, t_stack *stk_b);
size_t	get_square_root(size_t num);
size_t	push_target(t_stack *dest, t_stack *src, t_mode p_mode, size_t trgt);
t_chunk	*chunk_init(size_t size);
void	chunk_reset(t_chunk *chunk, size_t size);
void	chunk_update(t_chunk *chunk);
size_t	push_back(t_stack *stk_a, t_stack *stk_b, bool out);
size_t	move_to_top(t_stack *stk, int len, t_mode mode);
bool	arg_check(char **arg, size_t size);
bool	dup_check(int *arr, int num, size_t len);
size_t	count_strings(char **strs);
void	free_split(char **strs);
#endif
