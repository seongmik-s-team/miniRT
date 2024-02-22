/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:40 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/22 16:06:30 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// color 파라미터 생성자
t_color3	new_color3(double x, double y, double z)
{
	t_color3	new_color;

	new_color.x = x;
	new_color.y = y;
	new_color.z = z;
	return (new_color);
}

t_color3	to_color3(t_rgb rgb)
{
	t_color3	color;

	color.x = (double)rgb.r / RGB_MAX;
	color.y = (double)rgb.g / RGB_MAX;
	color.z = (double)rgb.b / RGB_MAX;
	return (color);
}
