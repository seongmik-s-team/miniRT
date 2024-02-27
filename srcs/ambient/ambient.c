/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:39:03 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/27 23:04:14 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	new_ambient(char **datas)
{
	t_ambient	ambient;

	if (get_arr_size(datas) != 3)
		pexit("[Parsing Error] Invalid number of ambient data");
	ambient.ratio = validate_ratio(ft_strtod(datas[1]));
	ambient.color = to_color3(str_to_rgb(datas[2], ','));
	return (ambient);
}
