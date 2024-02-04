/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:58:48 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:50:07 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"

t_point3	point3(t_coordinate x, t_coordinate y, t_coordinate z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vector3	point3_to_vector3(t_point3 p)
{
	t_vector3	v;

	v.x = p.x;
	v.y = p.y;
	v.z = p.z;
	return (v);
}
