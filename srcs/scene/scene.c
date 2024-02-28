/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:16:27 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/27 22:33:06 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->width = 1920;
	scene->height = 1080;
	scene->aspect_ratio = (double)scene->width / (double)scene->height;
	scene->objs = ft_new_list();
}

void	del_scene(t_scene *scene)
{
	ft_list_clear(scene->objs, del_object);
}
