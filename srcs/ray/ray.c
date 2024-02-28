/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:15:28 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:13:04 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_primary(t_camera cam, double x, double y)
{
	t_ray	ray;

	ray.origin = cam.origin;
	ray.direction = vunit(vminus(vplus(vplus(cam.lower_left,
					vmult(cam.horizontal, x)), vmult(cam.vertical, y)),
			cam.origin));
	return (ray);
}

int	sky_color(t_ray ray)
{
	double	sky_blue;

	sky_blue = 0.8 * (ray.direction.y + 1.0);
	return (to_hex(to_rgb(vplus(vmult((t_vec3)new_color3(1, 1, 1), 1.0
						- sky_blue), vmult((t_vec3)new_color3(0.5, 0.7, 1.0),
						sky_blue)))));
}

int	ray_color(t_scene *scene, t_ray ray)
{
	if (hit(scene, scene->objs->head, ray))
		return (to_hex(to_rgb(scene->rec.color)));
	return (sky_color(ray));
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	p;

	p = vplus((t_vec3)ray.origin, vmult(ray.direction, t));
	return (p);
}
