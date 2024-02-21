/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:29:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 17:36:50 by seongmik         ###   ########.fr       */
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
		scene_init(&scene);
		parser(argv[1], &scene);
    	mr_mlx_init(&scene);
	}
	return (SUCCESS);
}
