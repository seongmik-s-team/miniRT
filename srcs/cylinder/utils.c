/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:06:25 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/26 19:37:59 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color3	cal_color3(t_color3 obj_color, t_color3 lighted, t_color3 shadowed,
		t_ambient ambient)
{
	t_color3	result;
	t_color3	ambiented;

	ambiented = cmult(obj_color, vmult(ambient.color, ambient.ratio));
	result = cmult(obj_color, lighted);
	result = cmult(result, shadowed);
	result = cplus(result, ambiented);
	return (result);
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	p;

	p = vplus((t_vec3)ray.origin, vmult(ray.direction, t));
	return (p);
}
