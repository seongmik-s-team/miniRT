/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:16:27 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 21:46:09 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->width = 1200;
	scene->height = 900;
	scene->aspect_ratio = (double)scene->width / (double)scene->height;
	scene->objs = ft_new_list();
}
