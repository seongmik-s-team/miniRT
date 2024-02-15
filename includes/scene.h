/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:54:24 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/15 15:03:01 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas    canvas(int  width, int height);
t_camera    camera(t_canvas *canvas, t_point3 origin);
t_sphere    sphere(t_point3 center, double radius);

#endif
