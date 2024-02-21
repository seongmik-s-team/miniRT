/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:29:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 16:29:06 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

t_scene	*new_scene(void);

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (argc == 2)
	{
		// mlx 창 오픈
		scene = new_scene();
		parser(argv[1], scene);
    mr_mlx_init(&scene);
	}
	return (SUCCESS);
}

// *********************** temp ************************** //

t_scene	*new_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)ft_calloc(sizeof(t_scene));
	scene->light_list = ft_new_list();
	scene->object_list = ft_new_list();
	return (scene);
}

t_color3	to_color3(t_rgb rgb)
{
	t_color3 color;

	color.x = (double)rgb.r / 256;
	color.y = (double)rgb.g / 256;
	color.z = (double)rgb.b / 256;
	return (color);
}
