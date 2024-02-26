/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:32:57 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:14 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
ray가 닿은 spot에서부터 light까지 도달하는 벡터에 어떤 오브젝트가 hit 된다면 shadow안에 있는 것이다.
*/
t_color3	shadow(t_scene *scene, void *me, t_light light, t_point3 spot)
{
	t_ray		ray;
	t_recoder	rec;

	ray.origin = spot;
	ray.direction = vunit(vminus(light.point, spot));
	rec.p = scene->rec.p;
	rec.max_len = vlen(vminus(light.point, spot));
	if (just_hit(me, scene->objs->head, ray, &rec))
		return (new_color3(0, 0, 0));
	return (new_color3(1, 1, 1));
}
