/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:43:03 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 14:43:45 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	cmult(t_vec3 lv, t_vec3 rv)
{
	t_vec3	ret;

	ret.x = lv.x * rv.x;
	ret.y = lv.y * rv.y;
	ret.z = lv.z * rv.z;
	return (ret);
}
