/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:16:27 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:32 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene, char **argv)
{
	t_camera	cam;
	t_object	*obj;
	t_sphere	*sp;

	scene->width = ft_atoi(argv[1]);
	scene->height = ft_atoi(argv[2]);
	scene->aspect_ratio = (double)scene->width / (double)scene->height;
	cam.origin = (t_point3)new_vec3(0, 0, 0); // 임시 고정값
	cam.ov = new_vec3(0.0, 0.0, 1.0); // 임시 고정값
	cam.viewport_height = (double)scene->height;
	cam.viewport_width = scene->aspect_ratio * cam.viewport_height;
	cam.focal_length = 1.0;
	cam.horizontal = new_vec3(cam.viewport_width, 0, 0);
	cam.vertical = new_vec3(0, cam.viewport_height, 0);
	cam.lower_left = vminus(vminus(vminus(cam.origin, vdiv(cam.horizontal, 2)), \
					vdiv(cam.vertical, 2)), new_vec3(0, 0, cam.focal_length));
	scene->camera = cam;
	scene->objs = ft_new_list();
	scene->lights = ft_new_list();
	sp = new_sphere(new_point3(80, 0, 0), 3, new_color3(0, 0, 225));
	obj = new_object(SPHERE, sp);
	ft_list_append(scene->objs, ft_new_node(obj));
}
