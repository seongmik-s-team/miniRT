/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:40 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/27 22:48:32 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color3	new_color3(double x, double y, double z)
{
	t_color3	new_color;

	new_color.x = x;
	new_color.y = y;
	new_color.z = z;
	return (new_color);
}

t_rgb	to_rgb(t_color3 color)
{
	t_rgb	rgb;

	rgb.r = (int)(color.x * RGB_MAX);
	rgb.g = (int)(color.y * RGB_MAX);
	rgb.b = (int)(color.z * RGB_MAX);
	return (rgb);
}

int	to_hex(t_rgb rgb)
{
	return ((rgb.r * (1 << 16)) + (rgb.g * (1 << 8)) + (rgb.b));
}

t_color3	to_color3(t_rgb rgb)
{
	t_color3 color;

	color.x = (double)rgb.r / RGB_MAX;
	color.y = (double)rgb.g / RGB_MAX;
	color.z = (double)rgb.b / RGB_MAX;
	return (color);
}
