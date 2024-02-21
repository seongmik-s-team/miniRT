/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:57:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/21 16:47:54 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 동적할당 O, 사용 후 del_plane 호출
t_plane	*new_plane(char **datas)
{
	t_plane	*pl;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of plane data");
	pl = (t_plane *)ft_calloc(sizeof(t_plane));
	pl->center = str_to_point3(datas[1], ',');
	pl->axis = str_to_vec3(datas[2], ',');
	pl->color = to_color3(str_to_rgb(datas[3], ','));
	return (pl);
}
