/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:58:02 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/24 17:34:28 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray ray, double t);
t_bool		hit_cylinder_side(t_cylinder *cy, t_ray ray);
t_bool		hit_cylinder_cap(t_cylinder *cy, t_ray ray);

// 동적할당 O, 사용 후 del_cylinder 호출
t_cylinder	*new_cylinder(char **datas)
{
	t_cylinder	*cy;

	if (get_arr_size(datas) != 6)
		pexit("[Parsing Error] Invalid number of cylinder data");
	cy = (t_cylinder *)ft_calloc(sizeof(t_cylinder));
	cy->center = str_to_point3(datas[1], ',');
	cy->axis = validate_uvec(str_to_vec3(datas[2], ','));
	cy->diameter = ft_strtod(datas[3]) / 2.0;
	cy->height = ft_strtod(datas[4]);
	cy->color = to_color3(str_to_rgb(datas[5], ','));
	return (cy);
}

t_bool	hit_cylinder(t_cylinder *cylinder, t_ray ray)
{
	if (hit_cylinder_cap(cylinder, ray) || hit_cylinder_side(cylinder, ray))
		return (TRUE);
	return (FALSE);
}

// 원기둥의 옆면에 맞았는지 판정
t_bool	hit_cylinder_side(t_cylinder *cy, t_ray ray)
{
	t_point3	O;
	double		t;
	t_vec3		D;
	t_point3	C;
	t_vec3		V;
	double		r;
	double		a;
	double		b;
	t_vec3		OC;
	double		c;
	t_point3	P;
	t_point3	P_proj;
	double		distance;
	double		h;

	O = ray.origin;
	D = ray.direction;
	C = cy->center;
	V = cy->axis;
	r = cy->diameter;
	OC = (t_vec3)vminus(O, C);
	a = vdot(D, D) - pow(vdot(D, V), 2);
	b = 2.0 * ((vdot(D, OC) - vdot(D, V) * vdot(OC, V)));
	c = vdot(OC, OC) - pow(vdot(OC, V), 2) - r * r;
	if (b * b - 4 * a * c > 0)
	{
		t = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
		if (t < 0)
		{
			t = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
			if (t < 0)
				return (FALSE);
		}
		P = ray_at(ray, t);                                 // 표면에 위치한 교점
		P_proj = vplus(C, vmult(V, vdot(vminus(P, C), V))); // 교점P를 원기둥 축으로의 투영
		distance = vdot(vminus(P_proj, C), V);
		// C에서 부터 투영 점 P_proj까지의 거리
		h = cy->height;
		if (distance < 0 || distance > h)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

// 원기둥의 밑면에 맞았는지 판별
t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray ray)
{
	t_point3	c_bot;
	t_vec3		V;
	double		h;
	t_vec3		D;
	double		t;
	t_vec3		O;

	// t_point3	c_top;
	V = cy->axis;
	h = cy->height;
	D = ray.direction;
	O = ray.origin;
	c_bot = cy->center;
	// c_top = vplus(c_bot, vmult(V, h));
	if (vdot(V, D) == 0)
		return (FALSE);
	t = (vdot(vminus(c_bot, O), V)) / (vdot(D, V)); // 밑면의 평면 교점
	if (t < 0)
		return (FALSE);
	if (pow(vlen(vminus(vplus(O, vmult(D, t)), c_bot)), 2) < pow(cy->diameter,
																	2))
																		// 평면 상의 점이 원기둥 밑면의 원 안에 있는지 판별
		return (TRUE);
	return (FALSE);
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	p;

	p = vplus((t_vec3)ray.origin, vmult(ray.direction, t));
	return (p);
}
