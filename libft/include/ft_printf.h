/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:19:58 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/11 20:30:03 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		print_char(int ch);
int		print_int(int num);
int		print_str(char *str);
int		print_hexadecimal(unsigned int num, char format);
int		print_pointer(void *ptr);
int		print_unsigned_int(unsigned int num);
int		ft_printf(const char *str, ...);
#endif
