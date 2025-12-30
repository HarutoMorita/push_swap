/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 05:19:38 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/27 17:47:11 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_all(t_stack **stk, char **strs, bool is_split)
{
	if (is_split)
		free_split(strs);
	if (stk)
		free_stack(stk);
}

int	error_handle(t_stack **stk, char **strs, bool is_split)
{
	write(2, "Error\n", 6);
	free_all(stk, strs, is_split);
	return (1);
}
