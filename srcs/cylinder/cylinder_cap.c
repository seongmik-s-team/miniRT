/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:06 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/26 17:10:35 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray);
t_bool	circle_discriminant(t_circle circle, t_ray ray, double *t);

// 원기둥의 밑면에 맞았는지 판별
t_bool	hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray)
{
	// t_circle	top_cap;
	// t_circle	bot_cap;
	(void)scene;
	(void)cy;
	(void)ray;
	return (FALSE);
}

t_bool	just_hit_cylinder_cap(t_circle cap, t_ray ray, t_recoder *rec)
{
	double	t;

	if (circle_discriminant(cap, ray, &t))
	{
		if (t > rec->max_len)
			return (FALSE);
		rec->p = ray_at(ray, t);
		return (TRUE);
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
