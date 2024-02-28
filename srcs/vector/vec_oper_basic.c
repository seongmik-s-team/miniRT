/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:11:36 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 14:43:13 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vplus(t_vec3 lv, t_vec3 rv)
{
	t_vec3	ret;

	ret.x = lv.x + rv.x;
	ret.y = lv.y + rv.y;
	ret.z = lv.z + rv.z;
	return (ret);
}

t_vec3	cplus(t_vec3 lv, t_vec3 rv)
{
	t_vec3	ret;

	ret = vplus(lv, rv);
	if (1.0 < ret.x)
		ret.x = 1;
	if (1.0 < ret.y)
		ret.y = 1;
	if (1.0 < ret.z)
		ret.z = 1;
	if (ret.x < 0.0)
		ret.x = 0;
	if (ret.y < 0.0)
		ret.y = 0;
	if (ret.z < 0.0)
		ret.z = 0;
	return (ret);
}

t_vec3	vminus(t_vec3 lv, t_vec3 rv)
{
	t_vec3	ret;

	ret.x = lv.x - rv.x;
	ret.y = lv.y - rv.y;
	ret.z = lv.z - rv.z;
	return (ret);
}

t_vec3	vdiv(t_vec3 v, double value)
{
	t_vec3	ret;

	ret.x = v.x / value;
	ret.y = v.y / value;
	ret.z = v.z / value;
	return (ret);
}

t_vec3	vmult(t_vec3 v, double value)
{
	t_vec3	ret;

	ret.x = v.x * value;
	ret.y = v.y * value;
	ret.z = v.z * value;
	return (ret);
}
