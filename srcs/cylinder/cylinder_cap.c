/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:06 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 14:10:49 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	rec_near_cap(t_cylinder *cy, t_ray ray, t_recoder *rec);
// static void	recorder_copy(t_recoder from, t_recoder *to);

// t_bool	hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray)
// {
// 	t_recoder	rec;

// 	if (just_hit_cylinder_cap(cy, ray))
// 	{
// 		rec_near_cap(cy, ray, &rec);
// 		if (rec.max_len <= scene->rec.max_len)
// 		{
// 			recorder_copy(rec, &(scene->rec));
// 			scene->rec.color = cal_color3(scene, cy->color);
// 			return (TRUE);
// 		}
// 	}
// 	return (FALSE);
// }

// t_bool	just_hit_cylinder_cap(t_cylinder *cy, t_ray ray)
// {
// 	if (just_hit_circle(cy->topcap, ray))
// 		return (TRUE);
// 	if (just_hit_circle(cy->botcap, ray))
// 		return (TRUE);
// 	return (FALSE);
// }

// static void	rec_near_cap(t_cylinder *cy, t_ray ray, t_recoder *rec)
// {
// 	t_recoder	top_rec;
// 	t_recoder	bot_rec;
// 	t_bool		is_hit_top;
// 	t_bool		is_hit_bot;

// 	is_hit_top = hit_circle(cy->topcap, ray, &top_rec);
// 	is_hit_bot = hit_circle(cy->botcap, ray, &bot_rec);
// 	if (is_hit_top == FALSE && is_hit_bot == FALSE)
// 		return ;
// 	if (is_hit_top && is_hit_bot)
// 	{
// 		if (top_rec.max_len < bot_rec.max_len)
// 			recorder_copy(top_rec, rec);
// 		else
// 			recorder_copy(bot_rec, rec);
// 		return ;
// 	}
// 	if (is_hit_top)
// 		recorder_copy(top_rec, rec);
// 	else
// 		recorder_copy(bot_rec, rec);
// }

// static void	recorder_copy(t_recoder from, t_recoder *to)
// {
// 	to->p = from.p;
// 	to->nv = from.nv;
// 	to->max_len = from.max_len;
// }

t_bool		hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray);
t_bool		circle_discriminant(t_circle circle, t_ray ray, double *t,
				double *len);
t_circle	new_circle(t_vec3 axis, t_point3 center, double radius);

t_bool	hit_cylinder_cap(t_scene *scene, t_cylinder *cy, t_ray ray)
{
	t_point3	p;

	if (just_hit_cylinder_cap(cy, ray, &(scene->rec)))
	{
		p = scene->rec.p;
		if (vdot(ray.direction, scene->rec.nv) > 0) // 물체의 내부면 법선 벡터 뒤집깅~~!!
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
	t_circle	top_cap;
	t_circle	bot_cap;
	t_bool		flag;

	top_cap = new_circle(cy->axis, vplus(cy->center, vmult(cy->axis, 0.5
					* cy->height)), cy->diameter);
	bot_cap = new_circle(vmult(cy->axis, -1), vplus(cy->center, vmult(cy->axis,
					-0.5 * cy->height)), cy->diameter);
	flag = FALSE;
	if (circle_discriminant(top_cap, ray, &t, &len) && (len < rec->max_len))
	{
		rec->p = ray_at(ray, t);
		rec->nv = vunit(top_cap.axis);
		rec->max_len = len;
		flag = TRUE;
	}
	if (circle_discriminant(bot_cap, ray, &t, &len) && (len < rec->max_len))
	{
		rec->p = ray_at(ray, t);
		rec->nv = vunit(bot_cap.axis);
		rec->max_len = len;
		return (TRUE);
	}
	return (flag);
}

t_bool	circle_discriminant(t_circle circle, t_ray ray, double *t, double *len)
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
