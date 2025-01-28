/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_logic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:01:42 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 09:11:05 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_list	*before_last(t_list *head)
{
	t_list	*second_tail;

	second_tail = NULL;
	if (head && head->next)
	{
		while (head->next)
		{
			second_tail = head;
			head = head->next;
		}
	}
	return (second_tail);
}

void	reverse_rotate(t_list **head, char *operation)
{
	t_list	*second_tail;
	t_list	*last;

	if (head && *head && (*head)->next)
	{
		second_tail = before_last(*head);
		last = ft_lstlast(*head);
		last->next = *head;
		second_tail->next = NULL;
		*head = last;
		if (operation)
			ft_putstr_fd(operation);
	}
}

void	rotate_stacks(t_list **head1, t_list **head2)
{
	if (head1 && head1)
	{
		reverse_rotate(head1, "rrr\n");
		reverse_rotate(head2, NULL);
	}
}

void	max_reverse_rotate(t_list **head, char *type_reverse_rt, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		reverse_rotate(head, type_reverse_rt);
}

void	smart_reverse_rotate(t_list **head_a, t_list **head_b, int rra, int rrb)
{
	while (rra > 0 && rrb > 0)
	{
		rotate_stacks(head_a, head_b);
		rra--;
		rrb--;
	}
	if (rra)
		max_reverse_rotate(head_a, "rra\n", rra);
	if (rrb)
		max_reverse_rotate(head_b, "rrb\n", rrb);
}
