/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:02:59 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/26 04:20:52 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				num;
	size_t			rank;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;
typedef enum e_mode
{
	A = 0,
	AW = 1,
	B = 2,
	BW = 3,
	AB = 4,
	ABW = 5
}	t_mode;
typedef size_t	(*t_op_func)(t_stack *, t_mode);
void	free_stack(t_stack **stk);
t_node	*create_node(int num);
void	push_new(t_stack *stk, int num);
t_stack	*stack_init(void);
size_t	op_swap(t_stack *stk, t_mode mode);
size_t	op_push(t_stack *dest, t_stack *src, t_mode mode);
size_t	op_rotate(t_stack *stk, t_mode mode);
size_t	op_rotate_reverse(t_stack *stk, t_mode mode);
size_t	op_both(t_stack *stk_a, t_stack *stk_b, t_op_func op, t_mode mode);
void	renew_size(t_stack *stk);
size_t	get_max_rank(t_stack *stk);
size_t	get_min_rank(t_stack *stk);
size_t	get_rank_index(t_stack *stk, int index);
bool	is_sorted(t_stack *stk);
t_mode	out_check(t_mode mode, bool out);
t_stack	*copy_stack(t_stack *src);
t_node	*copy_nodes(t_node *src);
#endif
