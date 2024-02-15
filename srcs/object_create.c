/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:02:43 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/15 15:02:47 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_sphere    sphere(t_point3 center, double radius)
{
	t_sphere sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}
