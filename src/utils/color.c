/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:52:22 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(t_component r, t_component g, t_component b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
