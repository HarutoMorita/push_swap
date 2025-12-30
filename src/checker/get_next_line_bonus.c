/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 04:03:49 by hmorita           #+#    #+#             */
/*   Updated: 2025/11/19 15:25:25 by hmorita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static unsigned char	*cut_buf(t_fd_list *data, size_t len_cut)
{
	size_t			index;
	size_t			len_new;

	len_new = data->len_buf - len_cut;
	index = 0;
	while (index < len_new)
	{
		data->buffer[index] = data->buffer[index + len_cut];
		index++;
	}
	data->len_buf = len_new;
	return (data->buffer);
}

static unsigned char	*add_buf(t_fd_list *data, unsigned char *temp,
		size_t len_add)
{
	size_t			index;
	unsigned char	*new;
	size_t			len_new;

	len_new = data->len_buf + len_add;
	new = malloc(len_new);
	if (!new)
		return (NULL);
	index = 0;
	while (index < data->len_buf)
	{
		new[index] = data->buffer[index];
		index++;
	}
	while (index < len_new)
	{
		new[index] = temp[index - data->len_buf];
		index++;
	}
	data->len_buf = len_new;
	return (free(data->buffer), new);
}

static unsigned char	*get_line(t_fd_list *data)
{
	unsigned char	*line;
	size_t			len_line;
	size_t			index;

	len_line = 0;
	if (!check_newline(data->buffer, data->len_buf))
		len_line = data->len_buf;
	else
	{
		while (data->buffer[len_line] != '\n')
			len_line++;
		len_line++;
	}
	line = malloc(len_line + 1);
	if (!line)
		return (NULL);
	index = 0;
	while (index < len_line)
	{
		line[index] = data->buffer[index];
		index++;
	}
	line[index] = '\0';
	data->buffer = cut_buf(data, len_line);
	return (line);
}

static unsigned char	*read_fd(t_fd_list **data_ptr)
{
	int				bytes;
	unsigned char	*temp;
	t_fd_list		*data;

	data = *data_ptr;
	temp = malloc(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	while (!check_newline(data->buffer, data->len_buf))
	{
		bytes = read(data->fd, temp, BUFFER_SIZE);
		if (bytes < 0 || (bytes == 0 && data->len_buf == 0))
			return (free(temp), (unsigned char *)1);
		else if (bytes == 0)
			break ;
		data->buffer = add_buf(data, temp, bytes);
	}
	return (free(temp), get_line(data));
}

char	*get_next_line(int fd)
{
	unsigned char		*line;
	static t_fd_list	*fds_list;
	t_fd_list			*target;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX - 1)
		return (NULL);
	target = fdlist_find(fds_list, fd);
	if (!target)
	{
		target = fdlist_newdata(fd);
		if (!target)
			return (NULL);
		if (!fds_list)
			fds_list = target;
		else
			fdlist_append(&fds_list, target);
	}
	line = read_fd(&target);
	if (line == (unsigned char *)1)
		return (fdlist_remove(&fds_list, fd), NULL);
	if (!line)
		return (NULL);
	return ((char *)line);
}
