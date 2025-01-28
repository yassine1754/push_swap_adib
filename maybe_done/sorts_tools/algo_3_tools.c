/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:55:22 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 09:38:52 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	find_first_postion_recovery(t_list *head_a,
	t_list *head_b, t_cost_data *cost)
{
	int		indx;
	t_list	*tp;
	int		last_target;

	tp = head_a;
	last_target = 0;
	indx = 0;
	cost->position_a = -1;
	while (tp)
	{
		if ((head_b->target_idx < tp->target_idx) && cost->position_a == -1)
		{
			cost->position_a = indx;
			last_target = tp->target_idx;
		}
		else if ((tp->target_idx < last_target)
			&& (head_b->target_idx < tp->target_idx) && cost->position_a != -1)
		{
			cost->position_a = indx;
			last_target = tp->target_idx;
		}
		tp = tp->next;
		indx++;
	}
	min_index_in_stack(head_a, &cost->position_a);
}

void	recovere_all_chepeast(t_list **head_a, t_list **head_b,
			int *len_a, int len_b)
{
	t_cost_data	cost;
	int			index_min;

	cost.position_b = 0;
	index_min = -1;
	while (*head_b)
	{
		find_first_postion_recovery(*head_a, *head_b, &cost);
		caluclate_cost_to_push_in_position(&cost, *len_a, len_b);
		if (cost.op.total_ra)
			smart_rotate(head_a, head_b,
				cost.op.total_ra, cost.op.total_rb);
		if (cost.op.total_rra)
			smart_reverse_rotate(head_a, head_b,
				cost.op.total_rra, cost.op.total_rrb);
		push_data(head_b, head_a, "pa\n");
		*len_a += 1;
		len_b -= 1;
	}
	min_index_in_stack(*head_a, &index_min);
	if (index_min > *len_a)
		max_reverse_rotate(head_a, "rra\n", *len_a - index_min);
	else if (index_min > 0)
		max_rotate(head_a, "ra\n", index_min);
}
