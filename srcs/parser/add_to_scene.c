/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/23 17:09:35 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ambient	new_ambient(char **datas);
static t_camera		new_camera(t_scene *scene, char **datas);
static double		cal_focal_length(double vp_width, double fov);

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
	ambient.ratio = validate_ratio(ft_strtod(datas[1]));
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
	cam.ov = vunit(validate_uvec(str_to_vec3(datas[2], ',')));
	cam.fov = validate_fov(ft_strtod(datas[3]));
	cam.viewport_height = 1.5;
	cam.viewport_width = scene->aspect_ratio * cam.viewport_height;
	cam.focal_length = cal_focal_length(cam.viewport_width, cam.fov);
	cam.horizontal = vmult(vunit(vcross(new_vec3(0, 1, 0), cam.ov)),
			cam.viewport_width);
	cam.vertical = vmult(vunit(vcross(cam.ov, cam.horizontal)),
			-cam.viewport_height);
	cam.lower_left = vminus(vminus(vminus(cam.origin, vdiv(cam.horizontal, 2)),
				vdiv(cam.vertical, 2)), vmult(cam.ov, cam.focal_length));
	return (cam);
}

static double	cal_focal_length(double vp_width, double fov)
{
	double	fl;

	// focal_length = (뷰표트 width / 2) * (tan(fov / 2))
	// M_PI / 180은 도 단위를 라디안 단위로 변환하는 식
	fl = vp_width / (2 * tan((fov * M_PI / 180.0) / 2.0));
	return (fl);
}
