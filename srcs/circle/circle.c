/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:27:52 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 02:14:06 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	circle_discriminant(t_circle circle, t_ray ray, double *t);

t_circle	new_circle(t_vec3 axis, t_point3 center, double radius)
{
	t_circle	circle;

	circle.axis = axis;
	circle.center = center;
	circle.radius = radius;
	return (circle);
}

t_bool	hit_circle(t_circle circle, t_ray ray, t_recoder *rec)
{
	double		t;
	t_point3	p;

	if (circle_discriminant(circle, ray, &t))
	{
		p = ray_at(ray, t);
		rec->p = p;
		if (vdot(ray.direction, circle.axis) > 0)
			rec->nv = vmult(circle.axis, -1);
		else
			rec->nv = circle.axis;
		rec->max_len = vlen(vminus(p, ray.origin));
		return (TRUE);
	}
	return (FALSE);
}

t_bool	just_hit_circle(t_circle circle, t_ray ray)
{
	double	t;

	if (circle_discriminant(circle, ray, &t))
		return (TRUE);
	return (FALSE);
}

static t_bool	circle_discriminant(t_circle circle, t_ray ray, double *t)
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
	if (temp < 0)
		return (FALSE);
	distance = vlen(vminus(ray_at(ray, temp), c));
	if (pow(distance, 2) > pow(circle.radius, 2))
		return (FALSE);
	*t = temp;
	return (TRUE);
}
