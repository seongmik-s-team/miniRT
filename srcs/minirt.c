/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:29:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/20 19:58:58 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (argc != 3)
		return (FAILURE);
	scene_init(&scene, argv);
	mr_mlx_init(&scene);
	return (SUCCESS);
}
