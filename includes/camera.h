/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:18 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/04 18:27:57 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"

typedef struct s_camera	t_camera;

struct					s_camera
{
	t_point3			position;
	t_scalar			focal_length;
};

t_camera				camera(t_point3 origin, t_scalar focal_length);

#endif
