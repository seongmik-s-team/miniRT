/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/23 22:29:46 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	just_hit(void *me, t_node *objs, t_ray ray, t_recoder rec)
{
	t_object	*obj;

	while (objs)
	{
		obj = (t_object *)objs->content;
		if (me != obj->obj && just_type_hit(obj, ray, rec))
			return (TRUE);
		objs = objs->next;
	}
	return (FALSE);
}

t_bool	just_type_hit(t_object *obj, t_ray ray, t_recoder rec)
{
	if (obj->type == SPHERE)
		return (just_hit_sphere((t_sphere *)(obj->obj), ray, rec));
	else if (obj->type == PLANE)
		return (just_hit_plane((t_plane *)(obj->obj), ray, rec));
	return (FALSE);
}

// 단순히 hit 했는지 여부만 반환하는 함수
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
	// 구가 Ray의 origin보다 뒤에 있는지 체크한다. 뒤에 있다면 그리지 않는다.
	if (vdot(vminus(spot, ray.origin), ray.direction) / (vlen(vminus(spot,
					ray.origin)) * vlen(ray.direction)) < 0)
		return (FALSE);
	return (discriminant > 0 && vlen(vminus(hit_spot(sphere, ray),
				ray.origin)) <= rec.max_len);
}

// 단순히 hit 했는지 여부만 반환하는 함수
t_bool	just_hit_plane(t_plane *plane, t_ray ray, t_recoder rec)
{
	double		no;
	double		nv;
	double		d;
	double		t;
	t_point3	spot;

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
	return (vlen(vminus(spot, ray.origin)) <= rec.max_len);
}
