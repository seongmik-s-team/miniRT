/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:43 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/18 16:50:19 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// del : node의 content에 적용할 함수
void	ft_list_clear(t_list *list, void (*del)(void *))
{
	t_node	*node;
	t_node	*temp;

	if (list == 0)
		return ;
	node = list->head;
	while (node)
	{
		temp = node->next;
		del(node->content);
		free(node);
		node = temp;
	}
	free(list);
	list = 0;
}
