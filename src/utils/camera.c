/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:32:05 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:49:53 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "data.h"
#include "point3.h"

t_camera	camera(t_point3 origin, t_scalar focal_length)
{
	t_camera	camera;

	camera.position = origin;
	camera.focal_length = focal_length;
	return (camera);
}
