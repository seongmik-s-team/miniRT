/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:02:10 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 19:56:12 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	idx;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)ft_calloc(sizeof(char) * (len + 1));
	idx = 0;
	while (idx < len)
	{
		dup[idx] = s1[idx];
		idx++;
	}
	return (dup);
}
