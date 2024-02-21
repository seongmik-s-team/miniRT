/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:33:25 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/21 16:40:39 by jooahn           ###   ########.fr       */
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

t_point3	str_to_point3(char *str, char sep)
{
	return ((t_point3)str_to_vec3(str, sep));
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
	return (rgb);
}
