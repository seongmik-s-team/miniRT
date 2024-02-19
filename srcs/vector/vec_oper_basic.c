/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:11:36 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 19:30:36 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vadd(t_vec3 lv, t_vec3 rv)
{
	t_vec3	ret;

	ret.x = lv.x + rv.x;
	ret.y = lv.y + rv.y;
	ret.z = lv.z + rv.z;
	return (ret);
}

t_vec3	vsub(t_vec3 lv, t_vec3 rv)
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
