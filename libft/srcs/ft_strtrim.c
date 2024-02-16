/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:07:22 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 19:56:30 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	init_set(int is_set[256], char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	begin;
	size_t	end;
	int		is_set[256];
	char	*result;

	init_set(is_set, set);
	begin = 0;
	while (is_set[(unsigned char)s1[begin]])
		begin++;
	end = ft_strlen(s1);
	while (end > begin && is_set[(unsigned char)s1[end - 1]])
		end--;
	result = (char *)ft_calloc(sizeof(char) * (end - begin + 1));
	i = 0;
	while (i + begin < end)
	{
		result[i] = s1[i + begin];
		i++;
	}
	return (result);
}

static void	init_set(int is_set[256], char const *set)
{
	size_t	i;

	ft_bzero(is_set, 256 * sizeof(int));
	i = 0;
	while (set[i])
	{
		is_set[(unsigned char)set[i]] = 1;
		i++;
	}
}
