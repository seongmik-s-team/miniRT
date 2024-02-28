/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:03:30 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 14:49:05 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	new_vec3;

	new_vec3.x = x;
	new_vec3.y = y;
	new_vec3.z = z;
	return (new_vec3);
}

t_point3	new_point3(double x, double y, double z)
{
	t_point3	new_point3;

	new_point3.x = x;
	new_point3.y = y;
	new_point3.z = z;
	return (new_point3);
}

t_vec3	copy_vec3(t_vec3 *origin)
{
	t_vec3	new_vec3;

	new_vec3.x = origin->x;
	new_vec3.y = origin->y;
	new_vec3.z = origin->z;
	return (new_vec3);
}
