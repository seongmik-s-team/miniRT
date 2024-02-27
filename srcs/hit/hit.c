/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:12:59 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:15:58 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit(t_scene *scene, t_node *objs, t_ray ray)
{
	t_object	*obj;
	t_bool		is_hit;

	scene->rec.color = new_color3(0, 0, 0);
	scene->rec.max_len = 2147483647;
	is_hit = FALSE;
	while (objs)
	{
		obj = (t_object *)objs->content;
		if (type_hit(scene, obj, ray))
			is_hit = TRUE;
		objs = objs->next;
	}
	return (is_hit);
}

t_bool	type_hit(t_scene *scene, t_object *obj, t_ray ray)
{
	if (obj->type == SPHERE)
		return (hit_sphere(scene, (t_sphere *)(obj->obj), ray));
	else if (obj->type == PLANE)
		return (hit_plane(scene, (t_plane *)(obj->obj), ray));
	else if (obj->type == CYLINDER)
		return (hit_cylinder(scene, (t_cylinder *)(obj->obj), ray));
	return (FALSE);
}

t_point3	hit_spot(t_sphere *sphere, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;
	double	t[2];

	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	t[0] = (-b + sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
	t[1] = (-b - sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
	if (t[0] > t[1] && t[1] >= 0)
		t[0] = t[1];
	return (vplus(ray.origin, vmult(ray.direction, t[0])));
}
