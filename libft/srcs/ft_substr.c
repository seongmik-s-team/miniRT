/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:45:36 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 19:57:00 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	min(size_t size1, size_t size2);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	sub_len;

	s_len = ft_strlen(s);
	if (s_len <= (size_t)start)
	{
		substr = (char *)ft_calloc(sizeof(char));
		*substr = 0;
		return (substr);
	}
	sub_len = min(s_len - start, len);
	substr = (char *)ft_calloc(sizeof(char) * (sub_len + 1));
	while (sub_len-- > 0)
		substr[sub_len] = s[(size_t)start + sub_len];
	return (substr);
}

static size_t	min(size_t size1, size_t size2)
{
	if (size1 < size2)
		return (size1);
	return (size2);
}
