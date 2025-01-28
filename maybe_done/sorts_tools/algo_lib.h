/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:02 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:18:29 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_LIB_H
# define ALGO_LIB_H

# include "../Tools_dir/tools.h"
# include "../Operations/operations.h"
# include "../header.h"

typedef struct s_operation_need
{
	int	total_rra;
	int	total_rrb;
	int	total_ra;
	int	total_rb;
	int	total_need;
}	t_operation_need;
typedef struct s_cost_data
{
	int					position_a;
	int					position_b;
	int					len_stack_a;
	int					len_stack_b;
	t_operation_need	op;
}	t_cost_data;

// sort singles numbers
void		sort_single_3_head_a(t_list **head, int len);
void		sort_5_nums_only_low_to_high(t_list **head_a,
				t_list **head_b, int len);
void		sort_4_nums_only_low_to_heigh(t_list **head_a, t_list **head_b,
				int len, int range);
void		solutions_range_2_to_5(t_list **head_a, t_list **head_b, int len);
void		sort_first_3_stack_low_high(t_list **head);

// partition functions
void		partition(t_list **head_a, t_list **head_b, int range, int len);

// get max min

char		best_solution_to_get_min(t_list **head, int len, int range);
void		calculate_help_to_get_min(t_list *traverse, int len,
				int range, int *total);
int			max_of_two(int n1, int n2);
void		max_index_in_stack(t_list *search_in, int *position);
void		min_index_in_stack(t_list *search_in, int *position);

// cost help functions 
t_cost_data	find_the_cheapest(t_list *head_a, t_list *head_b,
				int len_a, int len_b);
void		recovere_all_chepeast(t_list **head_a, t_list **head_b,
				int *len_a, int len_b);
void		find_first_postion_recovery(t_list *head_a, t_list *head_b,
				t_cost_data *cost);
void		caluclate_cost_to_push_in_position(t_cost_data *cost_infos,
				int len_a, int len_b);
void		max_rotate_or_reverse_need(int index, int len,
				t_cost_data *cost_data, char type);

// algo functions
void		algo_version_3(t_list **head_a, t_list **head_b, int len_a);

#endif
