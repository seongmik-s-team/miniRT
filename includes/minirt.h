/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:37:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 21:18:55 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>

# include "libft.h"

# define ESC_KEY		53
# define EXIT_BUTTON	17

# define SUCCESS		0
# define FAILURE		1
# define TRUE			1
# define FALSE			0

# define RGB_MAX		255.999

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

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
	t_vec3				*position;
	enum e_object_type	type;
	void				*obj;
}				t_object;

typedef struct s_scene
{
	int		width;
	int		height;
}				t_scene;

typedef struct s_mlx_ptrs
{
	void	*mlx;
	void	*win;
}				t_mlx_ptrs;

/*********************************** mlx **************************************/
void		mr_mlx_init(t_scene *t_scene);
int			key_hook(int keycode, t_mlx_ptrs *ptrs);
int			exit_hook(t_mlx_ptrs *ptrs);

/********************************** object ************************************/
t_object	*new_object(t_point3 *position, enum e_object_type type, void *obj);

/********************************** vector ************************************/

t_vec3		*new_vec3(double x, double y, double z);
t_vec3		*copy_vec3(t_vec3 *origin);

t_vec3		vadd(t_vec3 lv, t_vec3 rv);
t_vec3		vsub(t_vec3 lv, t_vec3 rv);
t_vec3		vdiv(t_vec3 v, double value);
t_vec3		vmult(t_vec3 v, double value);
double		vdot(t_vec3 lv, t_vec3 rv);
t_vec3		vcross(t_vec3 lv, t_vec3 rv);
double		vlen(t_vec3 v);
t_vec3		vunit(t_vec3 v);

#endif
