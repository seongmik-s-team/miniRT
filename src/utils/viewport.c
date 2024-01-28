/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:48 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 16:22:05 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

t_viewport	viewport(int width, int height, int focal_length)
{
	t_viewport	vp;

	vp.width = width;
	vp.height = height;
	vp.aspect_ratio = (double)width / (double)height;
	vp.origin.x = 0 - (double)width / 2;
	vp.origin.y = 0 - (double)height / 2;
	vp.origin.z = 0 - focal_length;
	// vp.horizontal =
	return (vp);
}
