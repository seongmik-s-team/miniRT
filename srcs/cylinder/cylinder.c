/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:58:02 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/27 22:56:00 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		just_hit_cylinder_side(t_cylinder *cy, t_ray ray, t_recoder *rec);

t_cylinder	*new_cylinder(char **datas)
{
	t_cylinder	*cy;

	if (get_arr_size(datas) != 6)
		pexit("[Parsing Error] Invalid number of cylinder data");
	cy = (t_cylinder *)ft_calloc(sizeof(t_cylinder));
	cy->center = str_to_point3(datas[1], ',');
	cy->axis = vunit(validate_uvec(str_to_vec3(datas[2], ',')));
	cy->diameter = ft_strtod(datas[3]) / 2.0;
	cy->height = ft_strtod(datas[4]);
	cy->color = to_color3(str_to_rgb(datas[5], ','));
	return (cy);
}

t_bool	hit_cylinder(t_scene *scene, t_cylinder *cy, t_ray ray)
{
	t_bool	is_hit;

	is_hit = FALSE;
	if (hit_cylinder_side(scene, cy, ray))
		is_hit = TRUE;
	if (hit_cylinder_cap(scene, cy, ray))
		is_hit = TRUE;
	return (is_hit);
}

t_bool	just_hit_cylinder(t_cylinder *cy, t_ray ray, t_recoder *rec)
{
	t_bool	is_hit;

	is_hit = FALSE;
	if (just_hit_cylinder_side(cy, ray, rec))
		is_hit = TRUE;
	if (just_hit_cylinder_cap(cy, ray, rec))
		is_hit = TRUE;
	return (is_hit);
}
