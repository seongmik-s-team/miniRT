/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:40 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 15:54:54 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color3	new_color3(double x, double y, double z)
{
	t_color3	new_color;

	new_color.x = x;
	new_color.y = y;
	new_color.z = z;
	return (new_color);
}

t_color3	cal_color3(t_scene *scene, t_color3 obj_color)
{
	t_color3	result;
	t_recoder	rec;
	t_light		light;
	t_ambient	ambient;

	rec = scene->rec;
	light = scene->light;
	ambient = scene->ambient;
	result = obj_color;
	result = cmult(result, lighting(light, rec.p, rec.nv));
	result = cmult(result, shadow(scene, light, rec.p));
	result = cplus(result, cmult(obj_color, vmult(ambient.color,
					ambient.ratio)));
	return (result);
}

t_color3	to_color3(t_rgb rgb)
{
	t_color3	color;

	color.x = (double)rgb.r / RGB_MAX;
	color.y = (double)rgb.g / RGB_MAX;
	color.z = (double)rgb.b / RGB_MAX;
	return (color);
}
