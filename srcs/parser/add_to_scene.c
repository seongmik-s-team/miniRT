/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/21 21:49:36 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ambient	new_ambient(char **datas);
static t_camera		new_camera(t_scene *scene, char **datas);
static t_light		new_light(char **datas);

void	add_to_scene(t_scene *scene, char **datas)
{
	char	*id;

	if (get_arr_size(datas) < 1)
		pexit("[Parsing Error] data is empty");
	id = datas[0];
	if (ft_str_is_same(id, "A"))
		scene->ambient = new_ambient(datas);
	else if (ft_str_is_same(id, "C"))
		scene->camera = new_camera(scene, datas);
	else if (ft_str_is_same(id, "L"))
		scene->light = new_light(datas);
	else if (is_object(id))
		ft_list_append(scene->objs, ft_new_node(new_object(datas)));
	else
		pexit("[Parsing Error] Invalid identifier");
}

// 동적할당 X
static t_ambient	new_ambient(char **datas)
{
	t_ambient	ambient;

	if (get_arr_size(datas) != 3)
		pexit("[Parsing Error] Invalid number of ambient data");
	ambient.ratio = ft_strtod(datas[1]);
	ambient.color = to_color3(str_to_rgb(datas[2], ','));
	return (ambient);
}

// 동적할당 X
static t_camera	new_camera(t_scene *scene, char **datas)
{
	t_camera	cam;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of camera data");
	cam.origin = str_to_point3(datas[1], ',');
	cam.ov = str_to_vec3(datas[2], ',');
	cam.fov = ft_strtod(datas[3]);
	cam.viewport_height = 1.5;
	cam.viewport_width = scene->aspect_ratio * cam.viewport_height;
	cam.focal_length = 1.0;
	cam.horizontal = new_vec3(cam.viewport_width, 0, 0);
	cam.vertical = new_vec3(0, cam.viewport_height, 0);
	cam.lower_left = vminus(vminus(vminus(cam.origin, vdiv(cam.horizontal, 2)),
				vdiv(cam.vertical, 2)), new_vec3(0, 0, cam.focal_length));
	return (cam);
}

static t_light	new_light(char **datas)
{
	t_light	light;

	if (get_arr_size(datas) < 3 || 4 < get_arr_size(datas))
		pexit("[Parsing Error] Invalid number of light data");
	light.point = str_to_point3(datas[1], ',');
	light.ratio = ft_strtod(datas[2]);
	return (light);
}
