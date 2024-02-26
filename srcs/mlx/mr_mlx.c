/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:09:04 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/26 19:27:33 by seongmik         ###   ########.fr       */
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
	return ((rgb.r * (1 << 16)) + (rgb.g * (1 << 8)) + (rgb.b));
}

void	draw_screen(t_scene *scene, t_mlx_ptrs *ptrs)
{
	t_ray	ray;
	int		i;
	int		j;

	i = 0;
	while (i < scene->height)
	{
		j = 0;
		while (j < scene->width)
		{
			ray = ray_primary(scene->camera, (double)j / (double)scene->width,
					(double)(scene->height - i) / (double)scene->height);
			mr_mlx_pixel_put(&(ptrs->data), j, i, ray_color(scene, ray));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->data.img, 0, 0);
}

void	mr_mlx_init(t_scene *scene)
{
	t_mlx_ptrs	ptrs;

	ptrs.mlx = mlx_init();
	ptrs.win = mlx_new_window(ptrs.mlx, scene->width, scene->height, "miniRT");
	ptrs.data.img = mlx_new_image(ptrs.mlx, scene->width, scene->height);
	ptrs.data.addr = mlx_get_data_addr(ptrs.data.img, &ptrs.data.bits_per_pixel,
			&ptrs.data.line_length, &ptrs.data.endian);
	mlx_key_hook(ptrs.win, key_hook, &ptrs);
	mlx_hook(ptrs.win, EXIT_BUTTON, 0, exit_hook, &ptrs);
	draw_screen(scene, &ptrs);
	mlx_loop(ptrs.mlx);
}
