/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_of_5_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:46:01 by yadib             #+#    #+#             */
/*   Updated: 2025/01/22 21:25:41 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	sort_5_nums_only_low_to_high(t_list **head_a, t_list **head_b, int len)
{
	partition(head_a, head_b, (len / 2), len);
	sort_single_3_head_a(head_a, len);
	if ((*head_b)->content < (*head_b)->next->content)
		swap_single_stack(head_b, "sb\n");
	max_push(head_b, head_a, "pa\n", 2);
}
