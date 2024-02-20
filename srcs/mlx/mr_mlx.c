/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:09:04 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/20 21:05:42 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	to_rgb(t_color3 color)
{
	t_rgb	rgb;

	rgb.r = (int)(color.x * RGB_MAX);
	rgb.g = (int)(color.y * RGB_MAX);
	rgb.b = (int)(color.z * RGB_MAX);
	return (rgb);
}

int	to_hex(t_rgb rgb)
{
	return ((rgb.r * (2 << 16)) + (rgb.g * (2 << 8)) + (rgb.b));
}

void	draw_screen(t_scene *scene, t_mlx_ptrs *ptrs)
{
	t_ray		ray;
	int			i;
	int			j;

	i = 0;
	while (i < scene->height)
	{
		j = 0;
		ray = ray_primary(scene->camera, j / (double)scene->width, \
							(scene->height - i) / (double)scene->height);
		while (j < scene->width)
		{
			mlx_pixel_put(ptrs->mlx, ptrs->win, j, i, ray_color(scene, ray));
			j++;
		}
		i++;
	}
}

void	mr_mlx_init(t_scene *scene)
{
	t_mlx_ptrs	ptrs;

	ptrs.mlx = mlx_init();
	ptrs.win = mlx_new_window(ptrs.mlx, scene->width, scene->height, \
								"miniRT");
	mlx_key_hook(ptrs.win, key_hook, &ptrs);
	mlx_hook(ptrs.win, EXIT_BUTTON, 0, exit_hook, &ptrs);
	draw_screen(scene, &ptrs);
	mlx_loop(ptrs.mlx);
}
