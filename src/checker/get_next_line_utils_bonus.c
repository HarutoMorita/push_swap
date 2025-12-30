/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 04:03:36 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/11 22:54:31 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	fdlist_append(t_fd_list **list, t_fd_list *new)
{
	t_fd_list	*tail;

	if (!new)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tail = *list;
		while (tail->next)
			tail = tail->next;
		tail->next = new;
	}
}

t_fd_list	*fdlist_newdata(int fd)
{
	t_fd_list	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->buffer = malloc(BUFFER_SIZE);
	if (!data->buffer)
		return (free(data), NULL);
	data->len_buf = 0;
	data->fd = fd;
	data->next = NULL;
	return (data);
}
