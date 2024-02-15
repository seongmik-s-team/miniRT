/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/15 09:22:38 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

t_color	color(t_component r, t_component g, t_component b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	write_color(t_color color)
{
	printf("%d %d %d\n", (int)(255.999 * color.r), (int)(255.999 * color.g), (int)(255.999 * color.b));
}
