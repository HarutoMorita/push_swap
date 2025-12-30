/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 04:03:36 by hmorita           #+#    #+#             */
/*   Updated: 2025/12/30 16:28:07 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	check_newline(unsigned char *buffer, size_t len_buf)
{
	size_t	index;

	index = 0;
	while (index < len_buf)
	{
		if (buffer[index] == (unsigned char) '\n')
			return (true);
		index++;
	}
	return (false);
}

t_fd_list	*fdlist_find(t_fd_list *list, int fd)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->fd == fd)
			break ;
		list = list->next;
	}
	if (!list)
		return (NULL);
	return (list);
}

void	fdlist_remove(t_fd_list **list, int fd)
{
	t_fd_list	*curr;
	t_fd_list	*prev;

	curr = *list;
	prev = NULL;
	while (curr && curr->fd != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr)
	{
		if (prev)
			prev->next = curr->next;
		else
			*list = curr->next;
		if (curr->buffer)
			free(curr->buffer);
		free(curr);
	}
}

void	fdlist_clear(t_fd_list **list)
{
	t_fd_list	*curr;
	t_fd_list	*next;

	if (!list || !*list)
		return ;
	curr = *list;
	while (curr)
	{
		next = curr->next;
		free(curr->buffer);
		free(curr);
		curr = next;
	}
	*list = NULL;
}

t_fd_list	*fdlist_add(t_fd_list **list, int fd)
{
	t_fd_list	*new;
	t_fd_list	*tail;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->buffer = malloc(BUFFER_SIZE);
	if (!new->buffer)
		return (free(new), NULL);
	new->len_buf = 0;
	new->fd = fd;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		tail = *list;
		while (tail->next)
			tail = tail->next;
		tail->next = new;
	}
	return (new);
}
