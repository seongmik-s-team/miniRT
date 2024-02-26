/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:06 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/26 17:35:29 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray);
t_bool		circle_discriminant(t_circle circle, t_ray ray, double *t);
t_circle	new_circle(t_vec3 axis, t_point3 center, t_color3 color,
				double radius);

// 원기둥의 밑면에 맞았는지 판별
t_bool	hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray)
{
	t_point3	p;
	t_vec3		nv;

	if (just_hit_cylinder_cap(cy, ray, &(scene->rec)))
	{
		p = scene->rec.p;
		nv = scene->rec.nv;
		if (scene->rec.max_len >= vlen(vminus(ray.origin, p)))
		{
			scene->rec.color = cal_color3(cy->color, lighting(scene->light, p,
					nv), shadow(scene, cy, scene->light, p), scene->ambient);
			scene->rec.max_len = vlen(vminus(ray.origin, p));
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	just_hit_cylinder_cap(t_cylinder *cy, t_ray ray, t_recoder *rec)
{
	double		t;
	t_circle	top_cap;
	t_circle	bot_cap;

	top_cap = new_circle(cy->axis, vplus(cy->center, vmult(cy->axis, 0.5
				* cy->height)), cy->color, cy->diameter);
	bot_cap = new_circle(vmult(cy->axis, -1), vplus(cy->center, vmult(cy->axis,
				-0.5 * cy->height)), cy->color, cy->diameter);
	if (circle_discriminant(top_cap, ray, &t))
	{
		if (t < rec->max_len)
		{
			rec->p = ray_at(ray, t);
			rec->nv = cy->axis;
			return (TRUE);
		}
	}
	if (circle_discriminant(bot_cap, ray, &t))
	{
		if (t < rec->max_len)
		{
			rec->p = ray_at(ray, t);
			rec->nv = vmult(cy->axis, -1);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	circle_discriminant(t_circle circle, t_ray ray, double *t)
{
	t_point3	c;
	t_vec3		nv;
	double		temp;
	double		distance;

	c = circle.center;
	nv = circle.axis;
	if (vdot(nv, ray.direction) == 0)
		return (FALSE);
	temp = (vdot(vminus(c, ray.origin), nv)) / (vdot(ray.direction, nv));
	// 평면 방정식
	if (temp < 0)
		return (FALSE);
	distance = vlen(vminus(ray_at(ray, temp), c));
	if (pow(distance, 2) > pow(circle.radius, 2))
		return (FALSE);
	*t = temp;
	return (TRUE);
}

t_circle	new_circle(t_vec3 axis, t_point3 center, t_color3 color,
		double radius)
{
	t_circle	circle;

	circle.axis = axis;
	circle.center = center;
	circle.color = color;
	circle.radius = radius;
	return (circle);
}
