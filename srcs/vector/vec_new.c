/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:03:30 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 19:45:22 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 생성자 : 파라미터 생성
t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*new_vec3;

	new_vec3 = (t_vec3 *)ft_calloc(sizeof(t_vec3));
	new_vec3->x = x;
	new_vec3->y = y;
	new_vec3->z = z;
	return (new_vec3);
}

// 생성자 : 복사 생성
t_vec3	*copy_vec3(t_vec3 *origin)
{
	t_vec3	*new_vec3;

	new_vec3 = (t_vec3 *)ft_calloc(sizeof(t_vec3));
	new_vec3->x = origin->x;
	new_vec3->y = origin->y;
	new_vec3->z = origin->z;
	return (new_vec3);
}
