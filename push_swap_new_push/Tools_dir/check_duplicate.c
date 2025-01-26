/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:54:00 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 09:29:23 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	check_duplicate_list(t_list **head, int *len_sa, char *is_sort)
{
	t_list	*traverse;
	t_list	*current;

	if (*head == NULL || (*head)->next == NULL)
		return ('S');
	current = *head;
	while (current)
	{
		traverse = current->next;
		if (*is_sort == 'S' && traverse && current->content > traverse->content)
			*is_sort = NOT_SORTED;
		while (traverse)
		{
			if (current->content == traverse->content)
			{
				ft_lstclear(head);
				return (write(2, "Error\n", 7), 'F');
			}
			traverse = traverse->next;
		}
		current = current->next;
		*len_sa += 1;
	}
	return ('S');
}
