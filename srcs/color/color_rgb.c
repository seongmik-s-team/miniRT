/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:22:26 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 16:05:27 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_rgb(t_rgb rgb)
{
	if (rgb.r < 0 || rgb.r > 255)
		return (FALSE);
	if (rgb.g < 0 || rgb.g > 255)
		return (FALSE);
	if (rgb.b < 0 || rgb.b > 255)
		return (FALSE);
	return (TRUE);
}

t_rgb	to_rgb(t_color3 color)
{
	t_rgb	rgb;

	rgb.r = (int)(color.x * RGB_MAX);
	rgb.g = (int)(color.y * RGB_MAX);
	rgb.b = (int)(color.z * RGB_MAX);
	return (rgb);
}

int	to_hex_le(t_rgb rgb)
{
	return ((rgb.r * (1 << 16)) + (rgb.g * (1 << 8)) + (rgb.b));
}

int	to_hex_be(t_rgb rgb, int bits_per_pixel)
{
	if (bits_per_pixel == 32)
		return ((rgb.b * (1 << 24)) + (rgb.g * (1 << 16)) + (rgb.r * (1 << 8)));
	return ((rgb.b * (1 << 8)) + (rgb.g * (1 << 16)) + (rgb.r));
}
