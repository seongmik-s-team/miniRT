/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:47 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/27 22:47:26 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_to_scene(t_scene *scene, char **datas)
{
	char	*id;

	if (get_arr_size(datas) < 1)
		pexit("[Parsing Error] data is empty");
	id = datas[0];
	if (ft_str_is_same(id, "A"))
		scene->ambient = new_ambient(datas);
	else if (ft_str_is_same(id, "C"))
		scene->camera = new_camera(scene, datas);
	else if (ft_str_is_same(id, "L"))
		scene->light = new_light(datas);
	else if (is_object(id))
		ft_list_append(scene->objs, ft_new_node(new_object(datas)));
	else
		pexit("[Parsing Error] Invalid identifier");
}
