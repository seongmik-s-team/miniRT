/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:35 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 14:42:40 by seongmik         ###   ########.fr       */
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

t_bool	calc_hit_sphere(t_scene *scene, t_sphere *sphere, t_point3 spot,
		t_ray ray)
{
	scene->rec.p = spot;
	cal_color3(scene, sphere->color);
	scene->rec.color = cal_color3(scene, sphere->color);
	scene->rec.max_len = vlen(vminus(ray.origin, spot));
	return (TRUE);
}

t_bool	sphere_discriminant(t_sphere *sphere, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;

	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	return (((b * b) - (4.0 * a * c)) > 0);
}

t_bool	hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray)
{
	t_point3	spot;
	t_vec3		nv;

	if (sphere_discriminant(sphere, ray))
	{
		spot = hit_spot(sphere, ray);
		nv = vunit(vminus(spot, sphere->center));
		if (vdot(nv, ray.direction) > 0)
			nv = vmult(nv, -1);
		if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
						ray.origin)) * vlen(ray.direction)) < 0)
			return (FALSE);
		if (scene->rec.max_len >= vlen(vminus(ray.origin, spot)))
		{
			scene->rec.nv = nv;
			return (calc_hit_sphere(scene, sphere, spot, ray));
		}
	}
	return (FALSE);
}

t_bool	just_hit_sphere(t_sphere *sphere, t_ray ray, t_recoder rec)
{
	t_point3	spot;

	spot = hit_spot(sphere, ray);
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	return (sphere_discriminant(sphere, ray) && vlen(vminus(hit_spot(sphere,
					ray), ray.origin)) <= rec.max_len);
}
