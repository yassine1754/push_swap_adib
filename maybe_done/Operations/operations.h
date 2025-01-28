/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:08:17 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 10:20:34 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../Tools_dir/tools.h"
# include "../header.h"

void		push_data(t_list **src_head, t_list **dst_head, char *which_push);
void		swap_single_stack(t_list **head, char *type);
void		rotate_func(t_list **head, char *type_rotate);
void		reverse_rotate(t_list **head, char *operation);
void		rotate_stacks(t_list **head1, t_list **head2);
char		**free_all_array(char **array_of_array,
				int last_index, int total_array);
void		max_reverse_rotate(t_list **head, char *type_reverse_rt, int len);
void		max_rotate(t_list **head, char *type_rotate, int len);
void		max_push(t_list **src_head, t_list **dst_head,
				char *which_push, int len);
void		smart_reverse_rotate(t_list **head_a, t_list **head_b,
				int rra, int rrb);
void		smart_rotate(t_list **head_a, t_list **head_b,
				int ra, int rb);

#endif