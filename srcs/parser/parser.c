/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:27:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/22 17:47:13 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include <fcntl.h>

static t_bool	check_argv(char *argv);
static t_bool	check_ext(char *filename, char *ext);

void	parser(char *argv, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**datas;

	if (check_argv(argv) == FALSE)
		pexit("[Parsing Error] The file extension is not .rt");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		pexit("[Parsing Error] file open failed");
	line = get_trimmed_line(fd);
	while (line)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			line = get_trimmed_line(fd);
			continue ;
		}
		datas = ft_split(line, ' ');
		add_to_scene(scene, datas);
		free(line);
		ft_split_free(datas);
		line = get_trimmed_line(fd);
	}
	close(fd);
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
