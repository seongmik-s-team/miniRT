/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:27:05 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 21:17:05 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// key_hook : ESC 등의 키보드 버튼을 눌렀을 때 발생하는 이벤트
int	key_hook(int keycode, t_mlx_ptrs *ptrs)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(ptrs->mlx, ptrs->win);
		exit(SUCCESS);
	}
	return (SUCCESS);
}

// exit_hook : ESC 등의 키보드 버튼을 눌렀을 때 발생하는 이벤트
int	exit_hook(t_mlx_ptrs *ptrs)
{
	mlx_destroy_window(ptrs->mlx, ptrs->win);
	exit(SUCCESS);
	return (SUCCESS);
}
