/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 04:04:14 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/30 16:26:26 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_fd_list
{
	int					fd;
	unsigned char		*buffer;
	size_t				len_buf;
	struct s_fd_list	*next;
}	t_fd_list;
char		*get_next_line(int fd);
t_fd_list	*fdlist_find(t_fd_list *list, int fd);
bool		check_newline(unsigned char *buffer, size_t len_buf);
void		fdlist_remove(t_fd_list **list, int fd);
t_fd_list	*fdlist_add(t_fd_list **list, int fd);
void		fdlist_clear(t_fd_list **list);
#endif
