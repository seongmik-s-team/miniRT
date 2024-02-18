/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:53 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/18 16:44:11 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// i가 리스트 크기보다 크면 마지막 node 반환
// i가 음수면 첫 번째 node 반환
// 비어있는 리스트는 null pointer 반환
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
