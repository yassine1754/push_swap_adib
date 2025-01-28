/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_version_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:39:55 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 09:23:21 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	find_first_postion(t_list *head_a, t_list *head_b,
			t_cost_data *cost)
{
	int		indx;
	t_list	*tp;
	int		last;

	tp = head_b;
	last = 0;
	indx = 0;
	cost->position_b = -1;
	while (tp)
	{
		if (head_a->target_idx > tp->target_idx && cost->position_b == -1)
		{
			cost->position_b = indx;
			last = tp->target_idx;
		}
		else if ((tp->target_idx > last && head_a->target_idx > tp->target_idx)
			&& cost->position_b != -1)
		{
			cost->position_b = indx;
			last = tp->target_idx;
		}
		tp = tp->next;
		indx++;
	}
	max_index_in_stack(head_b, &cost->position_b);
}

void	compare_all_nums(t_list *head_a, t_list *head_b,
			t_cost_data *position_data)
{
	t_cost_data	temp_data;

	head_a = head_a->next;
	temp_data.position_a = 1;
	while (head_a)
	{
		find_first_postion(head_a, head_b, &temp_data);
		caluclate_cost_to_push_in_position(&temp_data,
			position_data->len_stack_a, position_data->len_stack_b);
		if (position_data->op.total_need
			> temp_data.op.total_need)
		{
			position_data->op.total_need = temp_data.op.total_need;
			position_data->position_a = temp_data.position_a;
			position_data->position_b = temp_data.position_b;
			position_data->op.total_ra = temp_data.op.total_ra;
			position_data->op.total_rb = temp_data.op.total_rb;
			position_data->op.total_rra = temp_data.op.total_rra;
			position_data->op.total_rrb = temp_data.op.total_rrb;
		}
		temp_data.position_a += 1;
		head_a = head_a->next;
	}
}

t_cost_data	find_the_cheapest(t_list *head_a, t_list *head_b,
		int len_a, int len_b)
{
	t_cost_data	position_data;

	position_data.position_a = 0;
	position_data.len_stack_a = len_a;
	position_data.len_stack_b = len_b;
	find_first_postion(head_a, head_b, &position_data);
	caluclate_cost_to_push_in_position(&position_data, len_a, len_b);
	compare_all_nums(head_a, head_b, &position_data);
	return (position_data);
}

void	push_all_cheapest(t_list **head_a, t_list **head_b,
		int *len_a, int *len_b)
{
	t_cost_data	position_data;

	max_push(head_a, head_b, "pb\n", 2);
	while (*len_a > 3)
	{
		position_data = find_the_cheapest(*head_a, *head_b, *len_a, *len_b);
		if (position_data.op.total_ra > 0 || position_data.op.total_rb > 0)
			smart_rotate(head_a, head_b,
				position_data.op.total_ra, position_data.op.total_rb);
		if (position_data.op.total_rra > 0 || position_data.op.total_rrb > 0)
			smart_reverse_rotate(head_a, head_b,
				position_data.op.total_rra, position_data.op.total_rrb);
		push_data(head_a, head_b, "pb\n");
		*len_a -= 1;
		*len_b += 1;
	}
	sort_first_3_stack_low_high(head_a);
}

void	algo_version_3(t_list **head_a, t_list **head_b, int len_a)
{
	int	len_b;

	if (len_a <= 5)
	{
		solutions_range_2_to_5(head_a, head_b, len_a);
		return ;
	}
	len_b = 2;
	len_a = len_a - 2;
	push_all_cheapest(head_a, head_b, &len_a, &len_b);
	recovere_all_chepeast(head_a, head_b, &len_a, len_b);
	return ;
}
