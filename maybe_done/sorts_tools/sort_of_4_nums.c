/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_of_4_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:35:40 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 08:53:41 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	sort_4_nums_only_low_to_heigh(t_list **head_a,
									t_list **head_b, int len, int range)
{
	partition(head_a, head_b, range, len);
	sort_first_3_stack_low_high(head_a);
	max_push(head_b, head_a, "pa\n", 1);
}
