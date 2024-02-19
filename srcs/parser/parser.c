/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:27:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/19 21:40:40 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include <fcntl.h>

static t_bool	check_argv(char *argv);
static t_bool	check_ext(char *filename, char *ext);
static void		pexit(const char *msg);

void	parser(char *argv)
{
	int	fd;

	// char	*line;
	if (check_argv(argv) == FALSE)
		pexit("The file extension is not .rt");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		pexit("file open failed");
	// line = get_next_line(fd);
	// while (line)
	// {
	// 	line = get_next_line(fd);
	// }
	close(fd);
}

static void	pexit(const char *msg)
{
	perror(msg);
	exit(FAILURE);
}

static t_bool	check_argv(char *argv)
{
	if (check_ext(argv, ".rt") == FALSE)
		return (FALSE);
	return (TRUE);
}

static t_bool	check_ext(char *filename, char *ext)
{
	size_t	flen;
	size_t	elen;
	size_t	cnt;

	if (!filename || !ext)
		return (FALSE);
	flen = ft_strlen(filename);
	elen = ft_strlen(ext);
	if (flen < elen)
		return (FALSE);
	cnt = 0;
	while (cnt++ < elen)
	{
		if (filename[flen - cnt] != ext[elen - cnt])
			return (FALSE);
	}
	return (TRUE);
}
