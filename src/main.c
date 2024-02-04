/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:04:15 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 16:18:20 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "mlx_handler.h"
#include "ray.h"
#include "viewport.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int			size_x;
	int			size_y;
	int			j;
	int			i;
	t_ray		ray;
	t_color		color;
	t_viewport	vp;

	size_x = 1920;
	size_y = 1080;
	// t_vars	vars;
	// vars.mlx_ptr = mlx_init();
	// vars.win_ptr = mlx_new_window(vars.mlx_ptr, size_x, size_y,
	// "Hello World!");
	// for (int i = 0; i < size_x; i++)
	// {
	// 	for (int j = 0; j < size_y; j++)
	// 	{
	// 		int r = (i * 2561424) % 256;
	// 		int g = (j * 25613412) % 256;
	// 		int b = (i * 256214) % 256;
	// 		int color = trans_trgb(0, r, g, b);
	// 		mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, i, j, color);
	// 	}
	// }
	// mlx_key_hook(vars.win_ptr, key_handler, &vars);
	// mlx_hook(vars.win_ptr, CLOSE, 0, close_event, &vars);
	// mlx_loop(vars.mlx_ptr);
	vp = viewport(size_x, size_y, 1);
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			ray = raycast(point3(0, 0, 0), vector3(0, 0, -1));
			color = ray_color(ray);
			printf("P3\n%d %d\n255\n", size_x, size_y);
		}
	}
	return (0);
}
