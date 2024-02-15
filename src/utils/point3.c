/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:58:48 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/04 18:29:46 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

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
