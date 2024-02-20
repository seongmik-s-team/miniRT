/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:35 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/20 20:12:33 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(t_point3 center, double diameter, t_color3 color)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)ft_calloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->diameter = diameter;
	sphere->color = color;
	return (sphere);
}
