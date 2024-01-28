/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:56:43 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 15:50:09 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

# include "data.h"
# include "vector3.h"

typedef struct s_point3	t_point3;

struct					s_point3
{
	t_coordinate		x;
	t_coordinate		y;
	t_coordinate		z;
};

t_point3				point3(t_coordinate x, t_coordinate y, t_coordinate z);
t_vector3				point3_to_vector3(t_point3 p);

#endif
