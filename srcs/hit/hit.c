/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:12:59 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/22 16:10:26 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit(t_scene *scene, t_node *objs, t_ray ray)
{
	t_object	*obj;

	while (objs)
	{
		obj = (t_object *)objs->content;
		if (type_hit(scene, obj, ray))
			return (TRUE);
		objs = objs->next;
	}
	return (FALSE);
}

t_bool	type_hit(t_scene *scene, t_object *obj, t_ray ray)
{
	if (obj->type == SPHERE)
		return (hit_sphere(scene, (t_sphere *)(obj->obj), ray));
	return (FALSE);
}

// ray가 구에 찍힌 점을 구한다.
t_point3	hit_spot(t_sphere *sphere, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;
	double	t[2];
	t_vec3	pt[2];

	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	t[0] = (-b + sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
	t[1] = (-b - sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
	pt[0] = vplus(ray.origin, vmult(ray.direction, t[0]));
	pt[1] = vplus(ray.origin, vmult(ray.direction, t[1]));
	// 두 벡터중 더 가까운 벡터를 구한다.
	if (vlen(pt[0]) < vlen(pt[1]))
		return (pt[0]);
	else
		return (pt[1]);
}

t_bool	hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray)
{
	double	a;
	double	b;
	double	c;

	t_color3 lighted; // 구의 법선벡터와 빛이 이루는 각도로 구한 빛의 세기에 따른 색
	t_point3 spot;    // 구의 중심부터 카메라에서 쏜 레이가 hit된 spot
	t_vec3 nv;        // 구의 중심부터 카메라에서 쏜 레이가 hit된 spot으로의 법선벡터
	t_vec3 oc;        //방향벡터로 나타낸 구의 중심.
	// a, b, c는 각각 t에 관한 2차 방정식의 계수
	double discriminant; //판별식
	(void)scene;
	oc = vminus(ray.origin, sphere->center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (sphere->diameter * sphere->diameter);
	// discriminant 는 판별식
	discriminant = (b * b) - (4.0 * a * c);
	// 판별식이 0보다 크다면 광선이 구를 hit한 것!
	if (discriminant > 0) // hit 했다면 sphere의 색이 광선의 색이다.
	{
		// 여기서 법선벡터와 spot을 구해서 빛을 곱해준다. (곱해주는 이유는 빛이 없으면 물체는 어두워야하기때문에)
		spot = hit_spot(sphere, ray);
		nv = vunit(vminus(spot, sphere->center));
		//구의 중심부터 카메라에서 쏜 레이가 hit된 spot으로의 법선벡터
		lighted = lighting(scene->light, spot, nv);
		// 구의 법선벡터와 빛이 이루는 각도로 구한 빛의 세기에 따른 색 (이 빛을 곱해준다.)
		scene->rec.color = cplus(cmult(sphere->color, lighted),
				cmult(sphere->color, vmult(scene->ambient.color,
						scene->ambient.ratio)));
	}
	return (discriminant > 0);
}
