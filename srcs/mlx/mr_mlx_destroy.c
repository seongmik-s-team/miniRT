/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_mlx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:20:40 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 15:27:57 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mr_mlx_destory(t_scene *scene)
{
	mlx_destroy_image(scene->ptrs.mlx, scene->ptrs.data.img);
	mlx_destroy_window(scene->ptrs.mlx, scene->ptrs.win);
}
