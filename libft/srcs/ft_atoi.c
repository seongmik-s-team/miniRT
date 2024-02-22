/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:16:21 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/22 17:12:55 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num(const char *str, int neg);

int	ft_atoi(const char *str)
{
	int	neg;

	neg = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = 1;
		str++;
	}
	return (get_num(str, neg));
}

static int	get_num(const char *str, int neg)
{
	int		num;
	int		cutoff;
	char	cutlim;

	num = 0;
	cutoff = FT_INT_MAX / 10;
	cutlim = FT_INT_MAX % 10 + '0';
	while (ft_isdigit(*str))
	{
		if ((num > cutoff) || (num == cutoff && *str > cutlim))
		{
			if (neg)
				return (-FT_INT_MAX - 1);
			return (FT_INT_MAX);
		}
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (neg)
		return (-num);
	return (num);
}
