/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:34:23 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/15 09:23:29 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "data.h"
# include "vector3.h"

typedef struct s_ray	t_ray;

struct					s_ray
{
	t_point3			origin;
	t_scalar			t;
	t_vector3			dir;
};

t_ray					ray(t_point3 origin, t_scalar t, t_vector3 dir);
t_point3				ray_at(t_ray ray);
t_ray					raycast(t_point3 origin, t_vector3 dir);
t_color					ray_color(t_ray ray);

#endif
