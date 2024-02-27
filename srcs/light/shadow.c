/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:32:57 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:17:43 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color3	shadow(t_scene *scene, t_light light, t_point3 spot)
{
	t_ray		ray;
	t_recoder	rec;

	ray.origin = spot;
	ray.direction = vunit(vminus(light.point, spot));
	rec.p = scene->rec.p;
	rec.max_len = vlen(vminus(light.point, spot));
	if (just_hit(scene->objs->head, ray, &rec))
		return (new_color3(0, 0, 0));
	return (new_color3(1, 1, 1));
}
