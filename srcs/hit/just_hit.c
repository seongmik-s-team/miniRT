/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:17:26 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	just_hit(t_node *objs, t_ray ray, t_recoder *rec)
{
	t_object	*obj;

	ray.origin = vplus(ray.origin, vmult(vunit(ray.direction), LITTLE));
	while (objs)
	{
		obj = (t_object *)objs->content;
		if (just_type_hit(obj, ray, rec))
			return (TRUE);
		objs = objs->next;
	}
	return (FALSE);
}

t_bool	just_type_hit(t_object *obj, t_ray ray, t_recoder *rec)
{
	if (obj->type == SPHERE)
		return (just_hit_sphere((t_sphere *)(obj->obj), ray, *rec));
	else if (obj->type == PLANE)
		return (just_hit_plane((t_plane *)(obj->obj), ray, *rec));
	else if (obj->type == CYLINDER)
		return (just_hit_cylinder((t_cylinder *)(obj->obj), ray, rec));
	return (FALSE);
}
