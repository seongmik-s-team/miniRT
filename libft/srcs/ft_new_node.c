/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:04:45 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 19:55:05 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node	*ft_new_node(void *content)
{
	t_node	*node;

	node = (t_node *)ft_calloc(sizeof(t_node));
	node->content = content;
	node->next = 0;
	node->prv = 0;
	return (node);
}
