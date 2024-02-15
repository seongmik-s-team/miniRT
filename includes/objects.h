/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:36:15 by ahn               #+#    #+#             */
/*   Updated: 2024/02/04 19:40:37 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vector3.h"

typedef	struct s_sphere t_sphere;

struct s_sphere
{
	t_point3	center;
	t_scalar	r;
	t_scalar	r_squared;
};


#endif