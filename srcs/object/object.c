/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:01:13 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 20:00:18 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 생성자 : 파라미터 생성자
t_object	*new_object(t_point3 *position, enum e_object_type type, void *obj)
{
	t_object	*new_obj;

	new_obj = (t_object *)ft_calloc(sizeof(t_object));
	new_obj->position = position;
	new_obj->type = type;
	new_obj->obj = obj;
	return (obj);
}
