/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:02:30 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/18 16:49:10 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// list의 뒤에 요소 삽입
void	ft_list_append(t_list *list, t_node *new)
{
	if (!(list->head) || !(list->tail))
	{
		new->prv = 0;
		new->next = 0;
		list->head = new;
		list->tail = new;
		return ;
	}
	list->tail->next = new;
	new->prv = list->tail;
	new->next = 0;
	list->tail = new;
}

void	ft_list_append_front(t_list *list, t_node *new)
{
	if (!(list->head) || !(list->tail))
	{
		new->prv = 0;
		new->next = 0;
		list->head = new;
		list->tail = new;
		return ;
	}
	list->head->prv = new;
	new->prv = 0;
	new->next = list->head;
	list->head = new;
}
