/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:21:37 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:50:29 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "data.h"
# include "point3.h"

typedef struct s_vector3	t_vector3;

struct						s_vector3
{
	t_component				x;
	t_component				y;
	t_component				z;
};

t_vector3					vector3(t_component x, t_component y,
								t_component z);
t_vector3					vector3_add(t_vector3 v1, t_vector3 v2);
t_vector3					vector3_sub(t_vector3 v1, t_vector3 v2);
t_vector3					vector3_mul(t_vector3 v, t_scalar multiplier);
t_vector3					vector3_div(t_vector3 v, t_scalar divisor);
t_scalar					vector3_len(t_vector3 v);
t_scalar					vector3_dot(t_vector3 v1, t_vector3 v2);
t_vector3					vector3_cross(t_vector3 v1, t_vector3 v2);
t_point3					vector3_head(t_vector3 v);

#endif
