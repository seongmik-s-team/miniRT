/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:16:27 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 22:46:49 by seongmik         ###   ########.fr       */
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
