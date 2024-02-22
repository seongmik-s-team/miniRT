/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:10:30 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/22 15:58:26 by seongmik         ###   ########.fr       */
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
/*
두 벡터가 이루는 각을 계산하는법
u,v를 내적하면 '|u||v|cos세타' 와 같다.
cos세타 = (u,v내적) / (|u||v|)
식을 정리하면 위와같고,
두 벡터가 이루는 각이 세타이므로
저 결과값이 1 (cos0도)이면 가장 크게
0(cos90도)이면 가장 작게
음수(cos90도이상)면 빛이 비추지 않는 것으로 처리한다.
*/
t_color3	lighting(t_light light, t_point3 spot, t_vec3 nv)
{
	t_vec3		lv;
	double		cos_theta;

	lv = vunit(vminus(light.point, spot));
	cos_theta = vdot(lv, nv) / (vlen(lv) * vlen(nv));
	// 두 벡터가 이루는 각도를 계산해서 빛의 값을 구한다.
	if (cos_theta <= 0) // 빛과 법선이 이루는 각이 90도 이상이면 빛이 비추지 않는다.
		cos_theta = 0.0;
	return (vmult(new_vec3(1, 1, 1), light.ratio * cos_theta));
}
