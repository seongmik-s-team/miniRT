/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:10:30 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 22:45:32 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	new_light(char **datas)
{
	t_light	light;

	if (get_arr_size(datas) < 3 || 4 < get_arr_size(datas))
		pexit("[Parsing Error] Invalid number of light data");
	light.point = str_to_point3(datas[1], ',');
	light.ratio = ft_strtod(datas[2]);
	return (light);
}

// spot 점에서 라이트와 물체의 법선벡터가 이루는 각으로 빛의 정도를 계산해서 반환해준다.
// nv는 그냥 법선벡터 방향 그대로 주면된다.
t_color3	lighting(t_light light, t_point3 spot, t_vec3 nv)
{
	t_vec3		lv;
	t_color3	lighted;

	(void)nv;
	lv = vunit(vminus(light.point, spot));
	// 두 벡터가 이루는 각도 계산해서 빛의 값을 구한다.
	lighted = new_vec3(1, 1, 1);
	return (lighted);
}
