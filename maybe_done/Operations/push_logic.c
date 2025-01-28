/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:07:00 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:20:38 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	push_data(t_list **src_head, t_list **dst_head, char *which_push)
{
	t_list	*temp;

	if (*src_head && !(*dst_head))
	{
		*dst_head = *src_head;
		*src_head = (*src_head)->next;
		(*dst_head)->next = NULL;
		ft_putstr_fd(which_push);
	}
	else if (*src_head && *dst_head)
	{
		temp = *src_head;
		*src_head = (*src_head)->next;
		temp->next = *dst_head;
		*dst_head = temp;
		ft_putstr_fd(which_push);
	}
}

void	max_push(t_list **src_head, t_list **dst_head,
			char *which_push, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		push_data(src_head, dst_head, which_push);
}

int	best_mid_idx(t_list *find_mid, int len_src)
{
	int	idx;
	int	min_idx;
	int	min_value;

	idx = 1;
	min_idx = 0;
	min_value = find_mid->content;
	find_mid = find_mid->next;
	while (find_mid && idx < 500 && idx < len_src)
	{
		if (find_mid->content < min_value && find_mid->target_idx > 100)
			min_idx = idx;
		idx++;
	}
	return (min_idx);
}
