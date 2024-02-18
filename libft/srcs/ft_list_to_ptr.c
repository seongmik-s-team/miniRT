/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:50:03 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/16 19:54:49 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_list_to_ptr(t_list *list, void (*del)(void *))
{
	void	**ptr;
	int		size;
	t_node	*node;
	int		i;

	size = ft_listsize(list);
	ptr = (void **)ft_calloc(sizeof(void *) * (size + 1));
	node = list->head;
	i = 0;
	while (node)
	{
		ptr[i++] = ft_strdup(node->content);
		node = node->next;
	}
	ft_list_clear(list, del);
	return (ptr);
}
