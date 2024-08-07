/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:33:25 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 02:23:11 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	str_to_vec3(char *str, char sep)
{
	t_vec3	vec;
	char	**datas;

	datas = ft_split(str, sep);
	if (get_arr_size(datas) != 3)
		pexit("[Parsing Error] Invalid number of data");
	vec.x = ft_strtod(datas[0]);
	vec.y = ft_strtod(datas[1]);
	vec.z = ft_strtod(datas[2]);
	ft_split_free(datas);
	return (vec);
}

t_rgb	str_to_rgb(char *str, char sep)
{
	t_rgb	rgb;
	char	**datas;

	datas = ft_split(str, sep);
	if (get_arr_size(datas) != 3)
		pexit("[Parsing Error] Invalid number of data");
	rgb.r = ft_atoi(datas[0]);
	rgb.g = ft_atoi(datas[1]);
	rgb.b = ft_atoi(datas[2]);
	ft_split_free(datas);
	if (!is_rgb(rgb))
		pexit("[Parsing Error] Invalid range of rgb");
	return (rgb);
}

double	validate_ratio(double ratio)
{
	if (ratio < 0.0 || 1.0 < ratio)
		pexit("[Parsing Error] ratio is out of range");
	return (ratio);
}

double	validate_fov(double fov)
{
	if (fov < 0.0 || fov > 180.0)
		pexit("[Parsing Error] fov is out of range");
	return (fov);
}

t_vec3	validate_uvec(t_vec3 uvec)
{
	if (uvec.x < -1.0 || uvec.x > 1.0)
		pexit("[Parsing Error] uvec is out of range");
	if (uvec.y < -1.0 || uvec.y > 1.0)
		pexit("[Parsing Error] uvec is out of range");
	if (uvec.z < -1.0 || uvec.z > 1.0)
		pexit("[Parsing Error] uvec is out of range");
	if (uvec.x == 0 && uvec.y == 0 && uvec.z == 0)
		pexit("[Parsing Error] Invalid uvec's data");
	return (uvec);
}
