/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:14:30 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/18 16:47:18 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinteger_util(const char *str, int neg);

// 문자열이 int 범위의 값인지 체크. 부호 하나 포함 가능
int	ft_isinteger(const char *str)
{
	int	neg;

	if (!str)
		return (0);
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
	return (isinteger_util(str, neg));
}

static int	isinteger_util(const char *str, int neg)
{
	int		num;
	int		cutoff;
	char	cutlim;

	num = 0;
	cutoff = FT_INT_MAX / 10;
	cutlim = FT_INT_MAX % 10 + '0';
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		if (num > cutoff)
			return (0);
		else if (num == cutoff)
		{
			if (!neg && *str > cutlim)
				return (0);
			if (neg && *str > cutlim + 1)
				return (0);
		}
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (1);
}
