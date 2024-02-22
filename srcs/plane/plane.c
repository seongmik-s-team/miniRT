/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:57:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/22 21:41:33 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 동적할당 O, 사용 후 del_plane 호출
t_plane	*new_plane(char **datas)
{
	t_plane	*pl;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of plane data");
	pl = (t_plane *)ft_calloc(sizeof(t_plane));
	pl->center = str_to_point3(datas[1], ',');
	pl->axis = str_to_vec3(datas[2], ',');
	pl->color = to_color3(str_to_rgb(datas[3], ','));
	return (pl);
}

t_bool	hit_plane(t_scene *scene, t_plane *plane, t_ray ray)
{
	double		no;
	double		nv;
	double		d;
	double		t;
	t_point3	spot;
	t_point3	shadowed;
	t_color3	lighted;

	// 두 벡터가 수직하는 경우 내적이 0이므로 ray가 평면에 포함된 경우이다. 교점존재x
	if (vdot(plane->axis, ray.direction) == 0)
		return (FALSE);
	no = vdot(plane->axis, ray.origin);
	nv = vdot(plane->axis, ray.direction);
	d = (plane->center.x * plane->axis.x) + (plane->center.y * plane->axis.y)
		+ (plane->center.z * plane->axis.z);
	t = -((no + d) / nv);
	spot = vplus(ray.origin, vmult(ray.direction, t)); // 평면과 ray의 교점
	// 평면이 Ray의 origin보다 뒤에 있는지 체크한다. 뒤에 있다면 그리지 않는다.
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	if (scene->rec.max_len >= vlen(vminus(ray.origin, spot)))
	{
		lighted = lighting(scene->light, spot, plane->axis);
		shadowed = shadow(scene, plane, scene->light, spot);
		scene->rec.color = cplus(cmult(cmult(plane->color, lighted), shadowed),
				cmult(plane->color, vmult(scene->ambient.color,
						scene->ambient.ratio)));
		scene->rec.max_len = vlen(vminus(ray.origin, spot));
		return (TRUE);
	}
	return (FALSE);
}
