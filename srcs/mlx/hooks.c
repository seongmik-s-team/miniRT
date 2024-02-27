/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:27:05 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:17:54 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_hook(int keycode, t_scene *scene)
{
	if (keycode == A_KEY)
	{
		scene->camera = move_camera(scene, vunit(vmult(scene->camera.horizontal,
					-1)));
		draw_screen_simple(scene, &scene->ptrs);
	}
	else if (keycode == D_KEY)
	{
		scene->camera = move_camera(scene, vunit(scene->camera.horizontal));
		draw_screen_simple(scene, &scene->ptrs);
	}
	else if (keycode == W_KEY)
	{
		scene->camera = move_camera(scene, vunit(vcross(scene->camera.vertical,
					scene->camera.horizontal)));
		draw_screen_simple(scene, &scene->ptrs);
	}
	else if (keycode == S_KEY)
	{
		scene->camera = move_camera(scene,
			vunit(vcross(scene->camera.horizontal, scene->camera.vertical)));
		draw_screen_simple(scene, &scene->ptrs);
	}
}

void	rotate_hook(int keycode, t_scene *scene)
{
	if (keycode == LEFT_KEY)
	{
		scene->camera = rotate_camera(scene, vunit(vplus(scene->camera.ov,
					vmult(scene->camera.horizontal, -0.0125))));
		draw_screen_simple(scene, &scene->ptrs);
	}
	else if (keycode == RIGHT_KEY)
	{
		scene->camera = rotate_camera(scene, vunit(vplus(scene->camera.ov,
					vmult(scene->camera.horizontal, 0.0125))));
		draw_screen_simple(scene, &scene->ptrs);
	}
	else if (keycode == DOWN_KEY)
	{
		scene->camera = rotate_camera(scene, vunit(vplus(scene->camera.ov,
					vmult(scene->camera.vertical, -0.0125))));
		draw_screen_simple(scene, &scene->ptrs);
	}
	else if (keycode == UP_KEY)
	{
		scene->camera = rotate_camera(scene, vunit(vplus(scene->camera.ov,
					vmult(scene->camera.vertical, 0.0125))));
		draw_screen_simple(scene, &scene->ptrs);
	}
}

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(scene->ptrs.mlx, scene->ptrs.win);
		exit(SUCCESS);
	}
	else if (keycode == R_KEY)
	{
		draw_screen(scene, &scene->ptrs);
	}
	else if (keycode == L_KEY)
	{
		set_light(scene, scene->camera.origin);
		draw_screen_simple(scene, &scene->ptrs);
	}
	else
	{
		move_hook(keycode, scene);
		rotate_hook(keycode, scene);
	}
	return (SUCCESS);
}

int	exit_hook(t_mlx_ptrs *ptrs)
{
	mlx_destroy_window(ptrs->mlx, ptrs->win);
	exit(SUCCESS);
	return (SUCCESS);
}
