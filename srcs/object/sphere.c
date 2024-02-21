/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:56:25 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/21 16:47:57 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 동적할당 O, 사용 후 del_sphere 호출
t_sphere	*new_sphere(char **datas)
{
	t_sphere	*sp;

	if (get_arr_size(datas) != 4)
		pexit("[Parsing Error] Invalid number of sphere data");
	sp = (t_sphere *)ft_calloc(sizeof(t_sphere));
	sp->center = str_to_point3(datas[1], ',');
	sp->diameter = ft_strtod(datas[2]);
	sp->color = to_color3(str_to_rgb(datas[3], ','));
	return (sp);
}
