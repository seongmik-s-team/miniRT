/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:21:27 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 16:19:34 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "point3.h"
# include "vector3.h"

typedef struct s_viewport	t_viewport;

struct						s_viewport
{
	int						width;
	int						height;
	double					aspect_ratio;
	t_point3				origin;
	t_vector3				vertical;
	t_vector3				horizontal;
};

t_viewport					viewport(int width, int height, int focal_length);

#endif
