/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:24:30 by yadib             #+#    #+#             */
/*   Updated: 2025/01/28 11:19:48 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheacker_bonus.h"

void	ft_lstclear_bonus(t_lines **lst)
{
	t_lines	*tracking;
	t_lines	*current;

	if (lst == NULL || *lst == NULL || lst == NULL)
		return ;
	tracking = *lst;
	while (tracking != NULL)
	{
		current = tracking->next;
		free(tracking->line);
		free(tracking);
		tracking = current;
	}
	*lst = NULL;
}

t_lines	*ft_lstnew_node(char *line)
{
	t_lines	*new_node;

	new_node = (t_lines *)malloc(sizeof(t_lines));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->line = line;
	return (new_node);
}
