/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:43:09 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:58:52 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "data.h"
#include "ray.h"

t_ray	ray(t_point3 origin, t_scalar t, t_vector3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.t = t;
	ray.dir = dir;
	return (ray);
}

t_point3	ray_at(t_ray ray)
{
	t_vector3	v;

	v = point3_to_vector3(ray.origin);
	v = vector3_add(v, vector3_mul(ray.dir, ray.t));
	return (vector3_head(v));
}

t_ray	raycast(t_point3 origin, t_vector3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.t = INF;
	ray.dir = dir;
	return (ray);
}

t_color	ray_color(t_ray ray)
{
	double	t;

	t = 0.5 * (ray.dir.y + 1.0);
	return (color(1 - 0.5 * t, 1 - 0.3 * t, 1));
}
