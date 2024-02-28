/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:03:31 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 16:41:37 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit_cylinder_side(t_scene *scene, t_cylinder *cy, t_ray ray);
t_bool	cylinder_side_discriminant(t_cylinder *cy, t_ray ray, double *t);

t_bool	hit_cylinder_side(t_scene *scene, t_cylinder *cy, t_ray ray)
{
	t_point3	p;
	t_point3	p_proj;
	t_vec3		nv;

	if (just_hit_cylinder_side(cy, ray, &(scene->rec)))
	{
		p = scene->rec.p;
		p_proj = vplus(cy->center, vmult(cy->axis, vdot(vminus(scene->rec.p,
							cy->center), cy->axis)));
		nv = vunit(vminus(p, p_proj));
		if (vdot(ray.direction, nv) > 0)
			nv = (vmult(nv, -1));
		if (scene->rec.max_len >= vlen(vminus(ray.origin, p)))
		{
			scene->rec.nv = nv;
			scene->rec.color = cal_color3(scene, cy->color);
			scene->rec.max_len = vlen(vminus(ray.origin, p));
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	just_hit_cylinder_side(t_cylinder *cy, t_ray ray, t_recoder *rec)
{
	double		t;
	t_point3	p;
	t_point3	p_proj;
	double		distance;

	if (cylinder_side_discriminant(cy, ray, &t))
	{
		p = ray_at(ray, t);
		p_proj = vplus(cy->center, vmult(cy->axis, vdot(vminus(p, cy->center),
						cy->axis)));
		distance = vdot(vminus(p_proj, cy->center), cy->axis);
		if (distance < -0.5 * cy->height || distance > 0.5 * cy->height)
			return (FALSE);
		if (vlen(vminus(ray.origin, p)) > rec->max_len)
			return (FALSE);
		rec->p = p;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	cylinder_side_discriminant(t_cylinder *cy, t_ray ray, double *t)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;

	oc = (t_vec3)vminus(ray.origin, cy->center);
	a = vdot(ray.direction, ray.direction) - pow(vdot(ray.direction, cy->axis),
			2);
	b = 2.0 * ((vdot(ray.direction, oc) - vdot(ray.direction, cy->axis)
				* vdot(oc, cy->axis)));
	c = vdot(oc, oc) - pow(vdot(oc, cy->axis), 2) - (cy->diameter
			* cy->diameter);
	if (b * b - 4 * a * c > 0)
	{
		if (((-b - sqrt(b * b - 4 * a * c)) / (2.0 * a)) >= 0)
			*t = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
		else if (((-b + sqrt(b * b - 4 * a * c)) / (2.0 * a)) >= 0)
			*t = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
		else
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
