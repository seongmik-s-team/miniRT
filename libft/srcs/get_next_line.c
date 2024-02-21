/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:38:21 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/20 17:19:23 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	load(char **data, char **saved_data);
static void	read_data(int fd, char **data, ssize_t *nl_idx);
static void	save(char *data, ssize_t nl_idx, char **saved_data);
static char	*get_line(char *data, ssize_t nl_idx);

char	*get_next_line(int fd)
{
	static char	*saved_data;
	char		*data;
	ssize_t		nl_idx;

	saved_data = 0;
	data = 0;
	load(&data, &saved_data);
	read_data(fd, &data, &nl_idx);
	save(data, nl_idx, &saved_data);
	return (get_line(data, nl_idx));
}

static void	load(char **data, char **saved_data)
{
	size_t	i;
	size_t	len;

	if (!*saved_data)
		return ;
	len = ft_strlen(*saved_data);
	*data = (char *)ft_calloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		(*data)[i] = (*saved_data)[i];
		i++;
	}
	free(*saved_data);
	*saved_data = 0;
}

static void	read_data(int fd, char **data, ssize_t *nl_idx)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	size_t	offset;

	*nl_idx = ft_strchr_idx(*data, '\n', 0);
	if (*nl_idx < 0)
		offset = ft_strlen(*data);
	while (*nl_idx < 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			free(*data);
		if (bytes <= 0)
			return ;
		*data = ft_strcat(*data, buffer, bytes);
		*nl_idx = ft_strchr_idx(*data, '\n', offset);
		offset += bytes;
	}
}

static void	save(char *data, ssize_t nl_idx, char **saved_data)
{
	size_t	i;
	size_t	len;

	if (nl_idx < 0)
		return ;
	len = ft_strlen(data) - (nl_idx + 1);
	if (len == 0)
	{
		*saved_data = 0;
		return ;
	}
	*saved_data = (char *)ft_calloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		(*saved_data)[i] = data[(nl_idx + 1) + i];
		i++;
	}
}

static char	*get_line(char *data, ssize_t nl_idx)
{
	ssize_t	i;
	char	*line;

	if (!data)
		return (0);
	if (nl_idx < 0)
		return (data);
	nl_idx++;
	line = (char *)ft_calloc(sizeof(char) * (nl_idx + 1));
	i = 0;
	while (i < nl_idx)
	{
		line[i] = data[i];
		i++;
	}
	free(data);
	return (line);
}
