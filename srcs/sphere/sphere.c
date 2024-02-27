/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:35 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:20:11 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(char **datas)
{
	t_sphere	*sp;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of sphere data");
	sp = (t_sphere *)ft_calloc(sizeof(t_sphere));
	sp->center = str_to_vec3(datas[1], ',');
	sp->diameter = ft_strtod(datas[2]) / 2.0;
	sp->color = to_color3(str_to_rgb(datas[3], ','));
	return (sp);
}

t_bool	hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_point3	shadowed;
	t_color3	lighted;
	t_point3	spot;
	t_vec3		nv;
	t_vec3		oc;
	double		discriminant;

	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant > 0)
	{
		spot = hit_spot(sphere, ray);
		nv = vunit(vminus(spot, sphere->center));
		if (vdot(nv, ray.direction) > 0)
			nv = vmult(nv, -1);
		if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
						ray.origin)) * vlen(ray.direction)) < 0)
			return (FALSE);
		lighted = lighting(scene->light, spot, nv);
		shadowed = shadow(scene, scene->light, spot);
		if (scene->rec.max_len >= vlen(vminus(ray.origin, spot)))
		{
			scene->rec.color = cplus(cmult(cmult(sphere->color, lighted),
					shadowed), cmult(sphere->color, vmult(scene->ambient.color,
						scene->ambient.ratio)));
			scene->rec.max_len = vlen(vminus(ray.origin, spot));
			return (TRUE);
		}
		else
			return (FALSE);
	}
	return (FALSE);
}

t_bool	just_hit_sphere(t_sphere *sphere, t_ray ray, t_recoder rec)
{
	double		a;
	double		b;
	double		c;
	t_vec3		oc;
	double		discriminant;
	t_point3	spot;

	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	discriminant = (b * b) - (4.0 * a * c);
	spot = hit_spot(sphere, ray);
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	return (discriminant > 0 && vlen(vminus(hit_spot(sphere, ray),
				ray.origin)) <= rec.max_len);
}
