/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:53 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/27 22:51:33 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_listget(t_list *list, int i)
{
	t_node	*node;

	if (!list)
		return (0);
	if (i >= ft_listsize(list))
		return (list->tail);
	node = list->head;
	while (node && i-- > 0)
		node = node->next;
	return (node);
}
