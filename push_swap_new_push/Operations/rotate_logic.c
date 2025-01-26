/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:47:25 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 16:03:30 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate_func(t_list **head, char *type_rotate)
{
	t_list	*head_node;
	t_list	*tail_node;

	tail_node = ft_lstlast(*head);
	if (*head && (*head)->next)
	{
		head_node = *head;
		*head = (*head)->next;
		head_node->next = NULL;
		tail_node->next = head_node;
		if (type_rotate)
			ft_putstr_fd(type_rotate);
	}
}

void	rotate_all_stack(t_list **first_head, t_list **second_head)
{
	rotate_func(second_head, "rr\n");
	rotate_func(first_head, NULL);
}

void	max_rotate(t_list **head, char *type_rotate, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		rotate_func(head, type_rotate);
}

void	smart_rotate(t_list **head_a, t_list **head_b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		rotate_all_stack(head_a, head_b);
		ra--;
		rb--;
	}
	if (ra)
		max_rotate(head_a, "ra\n", ra);
	if (rb)
		max_rotate(head_b, "rb\n", rb);
}
