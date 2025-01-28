/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkes_lists_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:28:28 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 16:02:54 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tracking;
	t_list	*current;

	if (lst == NULL || *lst == NULL || lst == NULL)
		return ;
	tracking = *lst;
	while (tracking != NULL)
	{
		current = tracking->next;
		free(tracking);
		tracking = current;
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tracking;

	if (lst == NULL)
		return (NULL);
	tracking = lst;
	while (tracking->next != NULL)
		tracking = tracking->next;
	return (tracking);
}
