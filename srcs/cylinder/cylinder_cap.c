/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:06 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 16:19:57 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	cap_discriminant(t_circle circle, t_ray ray, double *t,
					double *len);

t_bool	hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray)
{
	t_point3	p;

	if (just_hit_cylinder_cap(cy, ray, &(scene->rec)))
	{
		p = scene->rec.p;
		if (vdot(ray.direction, scene->rec.nv) > 0)
			scene->rec.nv = (vmult(scene->rec.nv, -1));
		if (scene->rec.max_len >= vlen(vminus(ray.origin, p)))
		{
			scene->rec.color = cal_color3(scene, cy->color);
			scene->rec.max_len = vlen(vminus(ray.origin, p));
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	just_hit_cylinder_cap(t_cylinder *cy, t_ray ray, t_recoder *rec)
{
	double		t;
	double		len;
	t_bool		flag;

	flag = FALSE;
	if (cap_discriminant(cy->topcap, ray, &t, &len) && (len < rec->max_len))
	{
		rec->p = ray_at(ray, t);
		rec->nv = vunit(cy->topcap.axis);
		rec->max_len = len;
		flag = TRUE;
	}
	if (cap_discriminant(cy->botcap, ray, &t, &len) && (len < rec->max_len))
	{
		rec->p = ray_at(ray, t);
		rec->nv = vunit(cy->botcap.axis);
		rec->max_len = len;
		return (TRUE);
	}
	return (flag);
}

static t_bool	cap_discriminant(t_circle circle, t_ray ray, double *t,
					double *len)
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
	*len = vlen(vminus(ray.origin, ray_at(ray, *t)));
	return (TRUE);
}
