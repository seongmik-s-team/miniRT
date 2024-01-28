/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:55 by jooahn            #+#    #+#             */
/*   Updated: 2024/01/26 16:04:01 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLER_H
# define MLX_HANDLER_H

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_vars;

enum		e_keys
{
	ESC = 53
};

enum		e_events
{
	CLOSE = 17
};

int			key_handler(int keycode, t_vars *vars);
int			close_event(void);

#endif
