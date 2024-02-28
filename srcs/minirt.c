/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:29:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 16:56:05 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (argc != 2)
		pexit("Invalid argument's count");
	scene_init(&scene);
	parser(argv[1], &scene);
	mr_mlx_init(&scene);
	del_scene(&scene);
	exit(SUCCESS);
}
