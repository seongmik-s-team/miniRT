/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:44:25 by jooahn            #+#    #+#             */
/*   Updated: 2023/10/20 23:46:36 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(void **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
	return ;
}

void	two_d_free(void **p)
{
	int	idx;

	idx = 0;
	while (p[idx])
	{
		free(p[idx]);
		idx++;
	}
	free(p);
}
