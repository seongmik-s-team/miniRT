/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:07 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 20:07:08 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_tohex(size_t n, int is_upper)
{
	char	*hex_num;
	int		len;
	char	hex;

	len = ft_ullen(n, 16);
	hex_num = (char *)ft_calloc(sizeof(char) * (len + 1));
	while (--len >= 0)
	{
		hex = FT_HEX[n % 16];
		if (is_upper)
			hex = ft_toupper(hex);
		hex_num[len] = hex;
		n /= 16;
	}
	return (hex_num);
}
