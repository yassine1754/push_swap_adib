/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_single_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:43 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:15:57 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	sort_single_3_head_a(t_list **head, int len)
{
	if ((*head)->target_idx == len - 3 && (*head)->next->target_idx == len - 1)
	{
		swap_single_stack(head, "sa\n");
		rotate_func(head, "ra\n");
	}
	if ((*head)->target_idx == len - 2 && (*head)->next->target_idx == len - 1)
		reverse_rotate(head, "rra\n");
	if ((*head)->target_idx == len - 1)
		rotate_func(head, "ra\n");
	if ((*head)->target_idx == len - 2)
		swap_single_stack(head, "sa\n");
}

void	sort_first_3_stack_low_high(t_list **head)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*head)->content;
	n2 = (*head)->next->content;
	n3 = (*head)->next->next->content;
	if (n1 > n2 && n2 > n3)
	{
		rotate_func(head, "ra\n");
		swap_single_stack(head, "sa\n");
	}
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		reverse_rotate(head, "rra\n");
		swap_single_stack(head, "sa\n");
	}
	else if (n1 > n2 && n1 < n3)
		swap_single_stack(head, "sa\n");
	else if (n1 > n2 && n1 > n3)
		rotate_func(head, "ra\n");
	else if (n1 < n2 && n1 > n3)
		reverse_rotate(head, "rra\n");
}
