/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:46:12 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/27 23:14:18 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_strtod(const char *str)
{
	double	result;
	int		sign;
	double	decimal_place;

	if (!str)
		pexit("[Parsing Error] Invalid data");
	result = 0.0;
	sign = 1;
	decimal_place = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		result = result + ((*str - '0') * decimal_place);
		decimal_place *= 0.1;
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str)
		pexit("[Parsing Error] Is not double");
	return (sign * result);
}

int	get_type(char *id)
{
	if (ft_str_is_same(id, "A"))
		return (AMBIENT);
	if (ft_str_is_same(id, "C"))
		return (CAMERA);
	if (ft_str_is_same(id, "L"))
		return (LIGHT);
	if (ft_str_is_same(id, "sp"))
		return (SPHERE);
	if (ft_str_is_same(id, "pl"))
		return (PLANE);
	if (ft_str_is_same(id, "cy"))
		return (CYLINDER);
	pexit("[Parsing Error] Invalid type");
	return (-1);
}

int	get_arr_size(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return (i);
	while (p[i])
		i++;
	return (i);
}

char	*get_trimmed_line(int fd)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trimmed_line = ft_strtrim(line, "\n");
	free(line);
	return (trimmed_line);
}
