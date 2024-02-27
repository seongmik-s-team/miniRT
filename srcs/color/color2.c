/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:22:26 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/28 02:22:55 by jooahn           ###   ########.fr       */
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
