/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:32:29 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:17:23 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

char	best_solution_to_get_min(t_list **head, int len, int range)
{
	int	total_operation;

	calculate_help_to_get_min(*head, len, range, &total_operation);
	if (total_operation == -1)
		return (PROBLEM);
	else if (total_operation < len / 2 && total_operation != 0)
		max_rotate(head, "ra\n", total_operation);
	else if (total_operation >= len / 2 && total_operation != 0)
		max_reverse_rotate(head, "rra\n", (len - total_operation));
	return (NOT_A_PROBLEM);
}

void	partition(t_list **head_a, t_list **head_b, int range, int len)
{
	t_list	*traverse;

	traverse = *head_a;
	while (best_solution_to_get_min(head_a, len, range) == NOT_A_PROBLEM)
	{
		traverse = *head_a;
		if (traverse->target_idx < range)
		{
			push_data(head_a, head_b, "pb\n");
			if ((*head_b)->next
				&& (*head_b)->content > (*head_b)->next->content)
				rotate_func(head_b, "rb\n");
			traverse = *head_a;
			len--;
		}
	}
}
