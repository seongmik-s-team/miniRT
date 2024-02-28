/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:29:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/27 22:49:51 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (argc == 2)
	{
		scene_init(&scene);
		parser(argv[1], &scene);
		mr_mlx_init(&scene);
		del_scene(&scene);
	}
	return (SUCCESS);
}
