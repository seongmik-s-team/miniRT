/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:29:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 21:53:45 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int	main(int argc, char *argv[])
{
	// t_scene	scene;

	// if (argc != 3)
	// 	return (FAILURE);
	// scene.width = ft_atoi(argv[1]);
	// scene.height = ft_atoi(argv[2]);
	// mr_mlx_init(&scene);
	// return (SUCCESS);
	if (argc == 3 && ft_str_is_same(argv[2], "--save"))
	{
		// 렌더링 된 이미지를 bmp 형식으로 변환해 저장.
	}
	if (argc == 2)
	{
		// mlx 창 오픈
		parser(argv[1]);
	}
	return (0);
}
