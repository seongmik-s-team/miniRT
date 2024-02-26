/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:57:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/26 17:21:00 by seongmik         ###   ########.fr       */
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
	pl->axis = vunit(validate_uvec(str_to_vec3(datas[2], ',')));
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
	t_vec3		n;

	// 두 벡터가 수직하는 경우 내적이 0이므로 ray가 평면에 포함된 경우이다. 교점존재x
	// 두 벡터가 이루는 각이 예각이면 뒷면에서 레이를 쏘는 것이므로 법선벡터를 뒤집는다.
	if (vdot(plane->axis, ray.direction) == 0)
		return (FALSE);
	else if (vdot(plane->axis, ray.direction) > 0)
		n = vmult(plane->axis, -1);
	else
		n = plane->axis;
	no = vdot(n, ray.origin);
	nv = vdot(n, ray.direction);
	d = (plane->center.x * n.x) + (plane->center.y * n.y) + (plane->center.z
			* n.z);
	t = -((no + d) / nv);
	spot = vplus(ray.origin, vmult(ray.direction, t)); // 평면과 ray의 교점
	// 평면이 Ray의 origin보다 뒤에 있는지 체크한다. 뒤에 있다면 그리지 않는다.
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	if (scene->rec.max_len >= vlen(vminus(ray.origin, spot)))
	{
		lighted = lighting(scene->light, spot, n);
		shadowed = shadow(scene, plane, scene->light, spot);
		scene->rec.color = cplus(cmult(cmult(plane->color, lighted), shadowed),
			cmult(plane->color, vmult(scene->ambient.color,
					scene->ambient.ratio)));
		scene->rec.max_len = vlen(vminus(ray.origin, spot));
		return (TRUE);
	}
	return (FALSE);
}
