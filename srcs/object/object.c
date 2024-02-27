/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:01:13 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/27 23:45:38 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*get_obj(char **datas);

t_object	*new_object(char **datas)
{
	t_object	*new_obj;

	if (get_arr_size(datas) < 1)
		pexit("[Parsing Error] Invalid data");
	if (!is_object(datas[0]))
		pexit("[Parsing Error] Is not object");
	new_obj = (t_object *)ft_calloc(sizeof(t_object));
	new_obj->type = get_type(datas[0]);
	new_obj->obj = get_obj(datas);
	return (new_obj);
}

void	del_object(void *obj)
{
	if (!obj)
		return ;
	free(((t_object *)obj)->obj);
	free(obj);
}

t_bool	is_object(char *id)
{
	if (get_type(id) == SPHERE)
		return (TRUE);
	if (get_type(id) == PLANE)
		return (TRUE);
	if (get_type(id) == CYLINDER)
		return (TRUE);
	return (FALSE);
}

static void	*get_obj(char **datas)
{
	int	type;

	type = get_type(datas[0]);
	if (type == SPHERE)
		return (new_sphere(datas));
	if (type == PLANE)
		return (new_plane(datas));
	if (type == CYLINDER)
		return (new_cylinder(datas));
	pexit("[Parsing Error] Invalid object type");
	return (NULL);
}
