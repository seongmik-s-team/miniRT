/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:27:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/27 23:36:23 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

static t_bool	check_ext(char *filename, char *ext);
static int		*get_counter(void);
static void		acl_counter(char **datas);
static t_bool	check_counter(void);

void	parser(char *argv, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**datas;

	if (check_ext(argv, ".rt") == FALSE)
		pexit("[Parsing Error] The file extension is not .rt");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		pexit("[Parsing Error] file open failed");
	line = get_trimmed_line(fd);
	while (line)
	{
		if (ft_strlen(line) != 0)
		{
			datas = ft_split(line, ' ');
			add_to_scene(scene, datas);
			acl_counter(datas);
		}
		free(line);
		ft_split_free(datas);
		line = get_trimmed_line(fd);
	}
	close(fd);
	if (check_counter() == FALSE)
		pexit("[Parsing Error] Invalid ACL count");
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

static int	*get_counter(void)
{
	static int	counter[3];

	return (counter);
}

static void	acl_counter(char **datas)
{
	int	*counter;
	int	type;

	counter = get_counter();
	type = get_type(datas[0]);
	if (type == AMBIENT)
		counter[0]++;
	else if (type == CAMERA)
		counter[1]++;
	else if (type == LIGHT)
		counter[2]++;
}

static t_bool	check_counter(void)
{
	int	*counter;

	counter = get_counter();
	if (counter[0] != 1)
		return (FALSE);
	if (counter[1] != 1)
		return (FALSE);
	if (counter[2] != 1)
		return (FALSE);
	return (TRUE);
}
