/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_version_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:43:38 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 08:55:35 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	solutions_range_2_to_5(t_list **head_a, t_list **head_b, int len)
{
	if (len == 2 && (*head_a)->target_idx == 1)
		swap_single_stack(head_a, "sa\n");
	else if (len == 3)
		sort_single_3_head_a(head_a, len);
	else if (len == 4)
		sort_4_nums_only_low_to_heigh(head_a, head_b, len, 1);
	else if (len == 5)
		sort_5_nums_only_low_to_high(head_a, head_b, len);
}
