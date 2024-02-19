/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:37:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 19:30:29 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <mlx.h>

# include "libft.h"

typedef t_vec3	t_point;
typedef t_vec3	t_color;
typedef t_vec3	t_ray;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

enum e_object_type
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
};

typedef struct s_object
{
	t_point				*position;
	enum e_object_type	type;
	void				*obj;
}				t_object;

#endif
