/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:01:13 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 16:56:19 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_obj_type(char *id);
static void	*get_obj(char **datas);

// 동적할당, 내부 obj 속성도 동적할당된 메모리. 사용 후 del_object 호출 필요
t_object	*new_object(char **datas)
{
	t_object	*new_obj;

	if (get_arr_size(datas) < 1)
		pexit("[Parsing Error] Invalid data");
	new_obj = (t_object *)ft_calloc(sizeof(t_object));
	new_obj->type = get_obj_type(datas[0]);
	new_obj->obj = get_obj(datas);
	return (new_obj);
}

t_bool	is_object(char *id)
{
	if (get_obj_type(id) == SPHERE)
		return (TRUE);
	if (get_obj_type(id) == PLANE)
		return (TRUE);
	if (get_obj_type(id) == CYLINDER)
		return (TRUE);
	return (FALSE);
}

// 동적할당 된 obj 반환. obj 타입에 맞는 소멸자 호출 필요
static void	*get_obj(char **datas)
{
	int	type;

	type = get_obj_type(datas[0]);
	if (type == SPHERE)
		return (new_sphere(datas));
	if (type == PLANE)
		return (new_plane(datas));
	if (type == CYLINDER)
		return (new_cylinder(datas));
	pexit("[Parsing Error] Invalid object type");
	return (NULL);
}

static int	get_obj_type(char *id)
{
	if (ft_str_is_same(id, "sp"))
		return (SPHERE);
	if (ft_str_is_same(id, "pl"))
		return (PLANE);
	if (ft_str_is_same(id, "cy"))
		return (CYLINDER);
	pexit("[Parsing Error] Invalid object type");
	return (-1);
}
