/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:16:02 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 14:09:36 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	cal_focal_length(double vp_width, double fov);
static t_vec3	safe_new_horizontal(t_vec3 ov, double viewport_width);

t_camera	new_camera(t_scene *scene, char **datas)
{
	t_camera	cam;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of camera data");
	cam.origin = str_to_vec3(datas[1], ',');
	cam.ov = vunit(validate_uvec(str_to_vec3(datas[2], ',')));
	cam.fov = validate_fov(ft_strtod(datas[3]));
	cam.viewport_height = 1.5;
	cam.viewport_width = scene->aspect_ratio * cam.viewport_height;
	cam.focal_length = cal_focal_length(cam.viewport_width, cam.fov);
	cam.horizontal = safe_new_horizontal(cam.ov, cam.viewport_width);
	cam.vertical = vmult(vunit(vcross(cam.horizontal, cam.ov)),
			cam.viewport_height);
	cam.lower_left = vplus(vplus(vplus(cam.origin, vdiv(cam.horizontal, -2.0)),
				vdiv(cam.vertical, -2.0)), vmult(cam.ov, cam.focal_length));
	return (cam);
}

t_camera	move_camera(t_scene *scene, t_point3 move)
{
	t_camera	cam;

	cam.origin = vplus(scene->camera.origin, move);
	cam.ov = scene->camera.ov;
	cam.fov = scene->camera.fov;
	cam.viewport_height = 1.5;
	cam.viewport_width = scene->aspect_ratio * cam.viewport_height;
	cam.focal_length = cal_focal_length(cam.viewport_width, cam.fov);
	cam.horizontal = safe_new_horizontal(cam.ov, cam.viewport_width);
	cam.vertical = vmult(vunit(vcross(cam.horizontal, cam.ov)),
			cam.viewport_height);
	cam.lower_left = vplus(vplus(vplus(cam.origin, vdiv(cam.horizontal, -2.0)),
				vdiv(cam.vertical, -2.0)), vmult(cam.ov, cam.focal_length));
	return (cam);
}

t_camera	rotate_camera(t_scene *scene, t_vec3 ov)
{
	t_camera	cam;

	cam.origin = scene->camera.origin;
	cam.ov = ov;
	cam.fov = scene->camera.fov;
	cam.viewport_height = 1.5;
	cam.viewport_width = scene->aspect_ratio * cam.viewport_height;
	cam.focal_length = cal_focal_length(cam.viewport_width, cam.fov);
	cam.horizontal = safe_new_horizontal(cam.ov, cam.viewport_width);
	cam.vertical = vmult(vunit(vcross(cam.horizontal, cam.ov)),
			cam.viewport_height);
	cam.lower_left = vplus(vplus(vplus(cam.origin, vdiv(cam.horizontal, -2.0)),
				vdiv(cam.vertical, -2.0)), vmult(cam.ov, cam.focal_length));
	return (cam);
}

static t_vec3	safe_new_horizontal(t_vec3 ov, double viewport_width)
{
	if (ov.x == 0 && (ov.y == 1 || ov.y == -1) && ov.z == 0)
		return (vmult(new_vec3(1, 0, 0), viewport_width));
	return (vmult(vunit(vcross(ov, new_vec3(0, 1, 0))), viewport_width));
}

static double	cal_focal_length(double vp_width, double fov)
{
	double	fl;

	fl = vp_width / (2 * tan((fov * M_PI / 180.0) / 2.0));
	return (fl);
}
