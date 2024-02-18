/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_list_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:44:40 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/18 16:46:22 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// // 미완성
// // base list의 at 위치에 insert 리스트 삽입. at이 base의 크기보다 크다면 맨 뒤에 삽입
// void	ft_insert_list_at(t_list *base, t_list *insert, int at)
// {
// 	t_node	*node;

// 	if (!base || !insert)
// 		return ;
// 	if (ft_list_is_empty(insert))
// 		return ;
// 	if (ft_list_is_empty(base))
// 	{
// 		base->head = insert->head;
// 		base->tail = insert->tail;
// 		return ;
// 	}
// 	if (at >= ft_listsize(base))
// 	{
// 		base->tail->next = insert->head;
// 		base->tail = insert->tail;
// 		return ;
// 	}
// 	if (at <= 0)
// 	{
// 		base->head->prv = insert->tail;
// 		base->head = insert->head;
// 		return ;
// 	}
// 	node = ft_listget(base, at);
// 	if (node->prv)
// 		node->prv->next = insert->head;
// 	insert->head->prv = node->prv;
// 	insert->tail->next = node;
// 	node->prv = insert->tail;
// }
