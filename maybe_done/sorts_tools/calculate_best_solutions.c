/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_best_solutions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:18:35 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:17:54 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	calculate_help_to_get_min(t_list *traverse,
								int len, int range, int *total)
{
	int		i;
	int		rotate_need;
	int		reverse_rotate_need;

	rotate_need = -1;
	reverse_rotate_need = -1;
	i = 0;
	while (traverse)
	{
		if (rotate_need == -1
			&& traverse->target_idx < range && (i < (len / 2)))
			rotate_need = i;
		else if (traverse->target_idx < range && (i >= (len / 2)))
			reverse_rotate_need = i;
		traverse = traverse->next;
		i++;
	}
	if (rotate_need == -1 && reverse_rotate_need != -1)
		*total = reverse_rotate_need;
	else if (reverse_rotate_need == -1 && rotate_need != -1)
		*total = rotate_need;
	else if (rotate_need < reverse_rotate_need)
		*total = rotate_need;
	else
		*total = reverse_rotate_need;
}

void	max_rotate_or_reverse_need(int index, int len,
	t_cost_data *cost_data, char type)
{
	if (index == 0)
		return ;
	if (len % 2)
	{
		if (index > (len / 2) && type == 'a')
			cost_data->op.total_rra = len - index;
		else if (index <= (len / 2) && type == 'a')
			cost_data->op.total_ra = index;
		if (index > (len / 2) && type == 'b')
			cost_data->op.total_rrb = len - index;
		else if (index <= (len / 2) && type == 'b')
			cost_data->op.total_rb = index;
		return ;
	}
	if (index >= (len / 2) && type == 'a')
		cost_data->op.total_rra = len - index;
	else if (index < (len / 2) && type == 'a')
		cost_data->op.total_ra = index;
	if (index >= (len / 2) && type == 'b')
		cost_data->op.total_rrb = len - index;
	else if (index < (len / 2) && type == 'b')
		cost_data->op.total_rb = index;
}

void	caluclate_cost_to_push_in_position(t_cost_data *cost_infos,
											int len_a, int len_b)
{
	cost_infos->op.total_ra = 0;
	cost_infos->op.total_rb = 0;
	cost_infos->op.total_rra = 0;
	cost_infos->op.total_rrb = 0;
	max_rotate_or_reverse_need(cost_infos->position_a, len_a, cost_infos, 'a');
	max_rotate_or_reverse_need(cost_infos->position_b, len_b, cost_infos, 'b');
	if (cost_infos->op.total_ra && cost_infos->op.total_rb)
		cost_infos->op.total_need = max_of_two(cost_infos->op.total_ra,
				cost_infos->op.total_rb);
	else if (cost_infos->op.total_rra && cost_infos->op.total_rrb)
		cost_infos->op.total_need = max_of_two(cost_infos->op.total_rra,
				cost_infos->op.total_rrb);
	else
		cost_infos->op.total_need = max_of_two(cost_infos->op.total_ra,
				cost_infos->op.total_rb)
			+ max_of_two(cost_infos->op.total_rra,
				cost_infos->op.total_rrb);
}
