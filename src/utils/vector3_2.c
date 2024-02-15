/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:59 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/04 18:30:27 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <math.h>

t_scalar	vector3_len(t_vector3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_scalar	vector3_dot(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector3	vector3_cross(t_vector3 v1, t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_vector3	vector3_normalize(t_vector3 v)
{
	t_scalar	length;

	length = vector3_len(v);
	if (length == 0)
		return (vector3(0, 0, 0));
	return (vector3_div(v, length));
}

t_point3	vector3_head(t_vector3 v)
{
	t_point3	head;

	head.x = v.x;
	head.y = v.y;
	head.z = v.z;
	return (head);
}
