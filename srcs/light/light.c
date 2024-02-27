/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:10:30 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/27 23:04:47 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	new_light(char **datas)
{
	t_light	light;

	if (get_arr_size(datas) < 3 || 4 < get_arr_size(datas))
		pexit("[Parsing Error] Invalid number of light data");
	light.point = str_to_point3(datas[1], ',');
	light.ratio = validate_ratio(ft_strtod(datas[2]));
	if (datas[3])
		str_to_rgb(datas[3], ',');
	return (light);
}

void	set_light(t_scene *scene, t_point3 set_point)
{
	scene->light.point = set_point;
}

t_color3	lighting(t_light light, t_point3 spot, t_vec3 nv)
{
	t_vec3	lv;
	double	cos_theta;

	lv = vunit(vminus(light.point, spot));
	cos_theta = vdot(lv, nv) / (vlen(lv) * vlen(nv));
	if (cos_theta <= 0)
		cos_theta = 0.0;
	return (vmult(new_vec3(1, 1, 1), light.ratio * cos_theta));
}
