/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:27:05 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 20:29:27 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_hook(int keycode, t_mlx_ptrs *ptrs)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(ptrs->mlx, ptrs->win);
		exit(SUCCESS);
	}
	return (SUCCESS);
}

int	exit_hook(t_mlx_ptrs *ptrs)
{
	mlx_destroy_window(ptrs->mlx, ptrs->win);
	exit(SUCCESS);
	return (SUCCESS);
}
