/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:57:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 14:37:50 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*new_plane(char **datas)
{
	t_plane	*pl;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of plane data");
	pl = (t_plane *)ft_calloc(sizeof(t_plane));
	pl->center = str_to_vec3(datas[1], ',');
	pl->axis = vunit(validate_uvec(str_to_vec3(datas[2], ',')));
	pl->color = to_color3(str_to_rgb(datas[3], ','));
	return (pl);
}

t_bool	calc_hit_plane(t_scene *scene, t_plane *plane, t_point3 spot, t_ray ray)
{
	scene->rec.p = spot;
	cal_color3(scene, plane->color);
	scene->rec.color = cal_color3(scene, plane->color);
	scene->rec.max_len = vlen(vminus(ray.origin, spot));
	return (TRUE);
}

t_bool	hit_plane(t_scene *scene, t_plane *plane, t_ray ray)
{
	double		no;
	double		nv;
	t_point3	spot;
	t_vec3		n;

	if (vdot(plane->axis, ray.direction) == 0)
		return (FALSE);
	else if (vdot(plane->axis, ray.direction) > 0)
		n = vmult(plane->axis, -1);
	else
		n = plane->axis;
	no = vdot(n, vminus(ray.origin, plane->center));
	nv = vdot(n, ray.direction);
	if (nv == 0)
		return (FALSE);
	spot = vplus(ray.origin, vmult(ray.direction, -(no / nv)));
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	if (scene->rec.max_len >= vlen(vminus(ray.origin, spot)))
	{
		scene->rec.nv = n;
		return (calc_hit_plane(scene, plane, spot, ray));
	}
	return (FALSE);
}

t_bool	just_hit_plane(t_plane *plane, t_ray ray, t_recoder rec)
{
	double		no;
	double		nv;
	double		t;
	t_point3	spot;
	t_vec3		n;

	if (vdot(plane->axis, ray.direction) == 0)
		return (FALSE);
	else if (vdot(plane->axis, ray.direction) > 0)
		n = vmult(plane->axis, -1);
	else
		n = plane->axis;
	no = vdot(n, vminus(ray.origin, plane->center));
	nv = vdot(n, ray.direction);
	t = -(no / nv);
	spot = vplus(ray.origin, vmult(ray.direction, t));
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	return (vlen(vminus(spot, ray.origin)) <= rec.max_len);
}
