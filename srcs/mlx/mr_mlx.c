/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:09:04 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 14:11:26 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_block(t_scene *scene, t_mlx_ptrs *ptrs, int y, int x)
{
	t_ray	ray;
	int		i;
	int		j;
	int		block_size;
	int		color;

	ray = ray_primary(scene->camera, (double)x / (double)scene->width,
			(double)(scene->height - y) / (double)scene->height);
	color = ray_color(scene, ray);
	block_size = (scene->height / 80);
	i = y;
	while (i < y + block_size && i < scene->height)
	{
		j = x;
		while (j < x + block_size && j < scene->width)
		{
			mr_mlx_pixel_put(&(ptrs->data), j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_screen_simple(t_scene *scene, t_mlx_ptrs *ptrs)
{
	int	i;
	int	j;
	int	block_size;

	block_size = (scene->height / 80);
	i = 0;
	while (i < scene->height)
	{
		j = 0;
		while (j < scene->width)
		{
			put_block(scene, ptrs, i, j);
			j += block_size;
		}
		i += block_size;
	}
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->data.img, 0, 0);
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
	scene->ptrs.mlx = mlx_init();
	scene->ptrs.win = mlx_new_window(scene->ptrs.mlx, scene->width,
			scene->height, "miniRT");
	scene->ptrs.data.img = mlx_new_image(scene->ptrs.mlx, scene->width,
			scene->height);
	scene->ptrs.data.addr = mlx_get_data_addr(scene->ptrs.data.img,
			&scene->ptrs.data.bits_per_pixel, &scene->ptrs.data.line_length,
			&scene->ptrs.data.endian);
	mlx_hook(scene->ptrs.win, 2, 0, key_hook, scene);
	mlx_hook(scene->ptrs.win, EXIT_BUTTON, 0, exit_hook, &scene->ptrs);
	draw_screen_simple(scene, &scene->ptrs);
	mlx_loop(scene->ptrs.mlx);
}
