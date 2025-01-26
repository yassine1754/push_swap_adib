/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:43:53 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 09:36:37 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_lib.h"

void	max_index_in_stack(t_list *search_in, int *position)
{
	int		idx;
	int		max_idx;
	int		max_value;

	if (*position != -1)
		return ;
	idx = 0;
	max_idx = 0;
	max_value = search_in->content;
	search_in = search_in->next;
	while (search_in)
	{
		idx++;
		if (search_in->content > max_value)
		{
			max_value = search_in->content;
			max_idx = idx;
		}
		search_in = search_in->next;
	}
	*position = max_idx;
}

void	min_index_in_stack(t_list *search_in, int *position)
{
	int		idx;
	int		max_idx;
	int		min_value;

	if (*position != -1)
		return ;
	idx = 0;
	max_idx = 0;
	min_value = search_in->content;
	search_in = search_in->next;
	while (search_in)
	{
		idx++;
		if (search_in->content < min_value)
		{
			min_value = search_in->content;
			max_idx = idx;
		}
		search_in = search_in->next;
	}
	*position = max_idx;
}

int	max_of_two(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}
