/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:44:28 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:20:12 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap_single_stack(t_list **head, char *type)
{
	t_list	*second;
	t_list	*temp_head;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp_head = *head;
		second = temp_head->next;
		temp_head->next = second->next;
		second->next = temp_head;
		*head = second;
		ft_putstr_fd(type);
	}
}
