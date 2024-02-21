/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:12:59 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 15:00:51 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit(t_scene *scene, t_node *objs, t_ray ray)
{
	t_object	*obj;

	while (objs)
	{
		obj = (t_object *)objs->content;
		if (type_hit(scene, obj, ray))
			return (TRUE);
		objs = objs->next;
	}
	return (FALSE);
}

t_bool	type_hit(t_scene *scene, t_object *obj, t_ray ray)
{
	if (obj->type == SPHERE)
		return (hit_sphere(scene, (t_sphere *)(obj->obj), ray));
	return (FALSE);
}

t_bool	hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray)
{
	t_vec3		oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double		a; 
	double		b;
	double		c;
	double		discriminant; //판별식

	(void)scene;
	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	// discriminant 는 판별식
	discriminant = (b * b) - (4.0 * a * c);
	// 판별식이 0보다 크다면 광선이 구를 hit한 것!
	return (discriminant > 0);
}
