/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:13 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/18 16:51:52 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// list의 맨앞의 요소 pop후 반환
t_node	*ft_list_pop(t_list *list)
{
	t_node	*target;

	if (ft_list_is_empty(list))
		return (NULL);
	target = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prv = NULL;
	else
		list->tail = NULL;
	target->next = NULL;
	return (target);
}
