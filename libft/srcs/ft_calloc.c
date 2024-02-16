/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:00:33 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 19:54:14 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t size)
{
	void	*pointer;

	pointer = (void *)malloc(size);
	if (!pointer)
		exit(EXIT_FAILURE);
	ft_bzero(pointer, size);
	return (pointer);
}
