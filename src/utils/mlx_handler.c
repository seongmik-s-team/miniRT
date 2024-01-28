/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:02:30 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 16:04:11 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_handler.h"
#include <mlx.h>
#include <stdlib.h>

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_event(void)
{
	exit(0);
}
