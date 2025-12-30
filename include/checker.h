/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 02:33:40 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/30 16:29:22 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"

bool	execute_operation(t_stack *stk_a, t_stack *stk_b, char *op);
bool	execute_swap(t_stack *stk_a, t_stack *stk_b, char *op);
bool	execute_push(t_stack *stk_a, t_stack *stk_b, char *op);
bool	execute_rotate_reverse(t_stack *stk_a, t_stack *stk_b, char *op);
bool	execute_rotate(t_stack *stk_a, t_stack *stk_b, char *op);
void	free_all(t_stack **stk, char **strs, bool is_split);
int		error_handle(t_stack **stk, char **strs, bool is_split);
#endif
