/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:41:09 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:50:29 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	vector3(t_component x, t_component y, t_component z)
{
	t_vector3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector3	vector3_add(t_vector3 v1, t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector3	vector3_sub(t_vector3 v1, t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector3	vector3_mul(t_vector3 v, t_scalar multiplier)
{
	t_vector3	result;

	result.x = v.x * multiplier;
	result.y = v.y * multiplier;
	result.z = v.z * multiplier;
	return (result);
}

t_vector3	vector3_div(t_vector3 v, t_scalar divisor)
{
	t_vector3	result;

	result.x = v.x / divisor;
	result.y = v.y / divisor;
	result.z = v.z / divisor;
	return (result);
}
