/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:32:57 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/26 17:29:44 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	inner_self_hit(void *me, t_node *objs, t_ray ray, t_recoder rec,
		t_light light)
{
	t_object	*obj;

	while (objs)
	{
		obj = (t_object *)objs->content;
		if (me == obj->obj && obj->type == SPHERE && vlen(vminus(light.point,
					ray.origin)) >= vlen(vminus(((t_sphere *)(obj->obj))->center,
					light.point)) && vlen(vminus(light.point,
					((t_sphere *)(obj->obj))->center)) > ((t_sphere *)(obj->obj))->diameter
			&& just_type_hit(obj, ray, &rec))
			return (TRUE);
		objs = objs->next;
	}
	return (FALSE);
}

/*
ray가 닿은 spot에서부터 light까지 도달하는 벡터에 어떤 오브젝트가 hit 된다면 shadow안에 있는 것이다.
*/
t_color3	shadow(t_scene *scene, void *me, t_light light, t_point3 spot)
{
	t_ray		ray;
	t_recoder	rec;
	t_bool		ret;

	ray.origin = spot;
	ray.direction = vunit(vminus(light.point, spot));
	rec.p = scene->rec.p;
	rec.max_len = vlen(vminus(light.point, spot));
	ret = just_hit(me, scene->objs->head, ray, &rec);
	if (!ret && inner_self_hit(me, scene->objs->head, ray, rec, light))
		ret = TRUE;
	if (ret)
		return (new_color3(0, 0, 0));
	return (new_color3(1, 1, 1));
}
