/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:21:37 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/04 18:28:40 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "data.h"

typedef struct s_point3		t_point3;
typedef struct s_vector3	t_vector3;

struct					s_point3
{
	t_coordinate		x;
	t_coordinate		y;
	t_coordinate		z;
};

struct						s_vector3
{
	t_component				x;
	t_component				y;
	t_component				z;
};

t_point3					point3(t_coordinate x, t_coordinate y, t_coordinate z);
t_vector3					point3_to_vector3(t_point3 p);

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
