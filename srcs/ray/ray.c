/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:15:28 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:01 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 왼쪽 위에서부터 광선을 쏘기 위해 뷰포트의 가장 왼쪽 가장 위 부터 가로로 u번째 세로로 v번째칸을 가리키는 초기 백터를 생성한다.
t_ray	ray_primary(t_camera cam, double x, double y)
{
	t_ray	ray;

	ray.origin = cam.origin; // 광선의 시작점은 카메라의 위치
	ray.direction = vunit(vminus(vplus(vplus(cam.lower_left, \
			vmult(cam.horizontal, x)), vmult(cam.vertical, y)), cam.origin));
	return (ray);
}

// y 좌표의 높이에 따라 선형적으로 파란색과 흰색을 섞습니다
int	sky_color(t_ray ray)
{
	double		sky_blue;

	sky_blue = 0.4 * (ray.direction.y + 1.0);
	return (to_hex(to_rgb(\
				vplus(vmult((t_vec3)new_color3(1, 1, 1), 1.0 - sky_blue), \
				vmult((t_vec3)new_color3(0.5, 0.7, 1.0), sky_blue)))));
}

// ray의 색을 결정합니다.
int	ray_color(t_scene *scene, t_ray ray)
{
	if (hit(scene, scene->objs->head, ray))
		return (to_hex(to_rgb(new_color3(\
				ray.direction.x, ray.direction.y, ray.direction.z))));
	return (sky_color(ray));
}
