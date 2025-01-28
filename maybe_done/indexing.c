/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:09:07 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 16:12:57 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_first_min(t_list **head, int *last_min)
{
	t_list	*traverse;
	t_list	*min_ptr;
	int		i;

	if (!(*head) || !(*head)->next)
		return (1);
	min_ptr = *head;
	traverse = (*head);
	i = 0;
	while (traverse)
	{
		if (min_ptr->content > traverse->content)
			min_ptr = traverse;
		traverse = traverse->next;
		i++;
	}
	min_ptr->target_idx = 0;
	*last_min = min_ptr->content;
	return (i);
}

void	index_single_node(t_list **head, int *last_min, int *target_id)
{
	t_list	*traverse;
	t_list	*min_ptr;
	int		i;

	if (!(*head) || !(*head)->next)
		return ;
	i = 0;
	min_ptr = *head;
	traverse = min_ptr;
	while (traverse)
	{
		if ((*last_min < traverse->content
				&& min_ptr->content > traverse->content)
			|| min_ptr->content <= *last_min)
			min_ptr = traverse;
		traverse = traverse->next;
		i++;
	}
	min_ptr->target_idx = *target_id;
	*last_min = min_ptr->content;
	*target_id += 1;
}

void	indexing_list(t_list **head)
{
	int	target_id;
	int	len;
	int	last_min;

	target_id = 1;
	len = find_first_min(head, &last_min);
	while (target_id < len)
		index_single_node(head, &last_min, &target_id);
	return ;
}

char	check_is_sort(t_list **head)
{
	t_list	*traverse;
	t_list	*next;

	if (*head == NULL)
		return (PROBLEM);
	traverse = *head;
	next = traverse->next;
	while (traverse->next)
	{
		if (traverse->content > next->content)
			return (PROBLEM);
		traverse = next;
		next = traverse->next;
	}
	return (NOT_A_PROBLEM);
}
