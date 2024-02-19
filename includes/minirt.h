/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:37:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 21:37:35 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef int				t_bool;

typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;
typedef struct s_vec3	t_ray;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

enum					e_object_type
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
}						t_object;

//----------------------------------parser-------------------------------------//
void					parser(char *argv);

#endif
