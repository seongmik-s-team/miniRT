/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/21 16:44:29 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ambient	new_ambient(char **datas);
static t_camera		new_camera(char **datas);
static t_light		*new_light(char **datas);

void	add_to_scene(t_scene *scene, char **datas)
{
	char	*id;

	if (get_arr_size(datas) < 1)
		pexit("[Parsing Error] data is empty");
	id = datas[0];
	if (ft_str_is_same(id, "A"))
		scene->ambient = new_ambient(datas);
	else if (ft_str_is_same(id, "C"))
		scene->camera = new_camera(datas);
	else if (ft_str_is_same(id, "L"))
		ft_list_append(scene->light_list, ft_new_node(new_light(datas)));
	else if (is_object(id))
		ft_list_append(scene->object_list, ft_new_node(new_object(datas)));
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
static t_camera	new_camera(char **datas)
{
	t_camera	camera;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of camera data");
	camera.origin = str_to_point3(datas[1], ',');
	camera.ov = str_to_vec3(datas[2], ',');
	camera.fov = ft_strtod(datas[3]);
	return (camera);
}

// 동적할당 O, 사용 후 del_light 호출 필수
static t_light	*new_light(char **datas)
{
	t_light	*light;

	if (get_arr_size(datas) != 3)
		pexit("[Parsing Error] Invalid number of light data");
	light = (t_light *)ft_calloc(sizeof(t_light));
	light->point = str_to_point3(datas[1], ',');
	light->ratio = ft_strtod(datas[2]);
	return (light);
}
