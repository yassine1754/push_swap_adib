/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheacker_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:52:20 by yadib             #+#    #+#             */
/*   Updated: 2025/01/26 08:54:23 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheacker_bonus.h"

char	push_cheacker(t_list **head_a, t_list **head_b, char *line)
{
	if (ft_strcmp(line, "pb\n") == NOT_A_PROBLEM)
	{
		push_data(head_a, head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "pa\n") == NOT_A_PROBLEM)
	{
		push_data(head_b, head_a, NULL);
		return (NOT_A_PROBLEM);
	}
	else
		return (PROBLEM);
}

char	reverse_cheacker(t_list **head_a, t_list **head_b, char *line)
{
	if (ft_strcmp(line, "rra\n") == NOT_A_PROBLEM)
	{
		reverse_rotate(head_a, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "rrb\n") == NOT_A_PROBLEM)
	{
		reverse_rotate(head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "rrr\n") == NOT_A_PROBLEM)
	{
		reverse_rotate(head_a, NULL);
		reverse_rotate(head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else
		return (PROBLEM);
}

char	rotate_cheacker(t_list **head_a, t_list **head_b, char *line)
{
	if (ft_strcmp(line, "ra\n") == NOT_A_PROBLEM)
	{
		rotate_func(head_a, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "rb\n") == NOT_A_PROBLEM)
	{
		rotate_func(head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "rr\n") == NOT_A_PROBLEM)
	{
		rotate_func(head_a, NULL);
		rotate_func(head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else
		return (PROBLEM);
}

char	swap_cheacker(t_list **head_a, t_list **head_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == NOT_A_PROBLEM)
	{
		swap_single_stack(head_a, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "sb\n") == NOT_A_PROBLEM)
	{
		swap_single_stack(head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else if (ft_strcmp(line, "ss\n") == NOT_A_PROBLEM)
	{
		swap_single_stack(head_a, NULL);
		swap_single_stack(head_b, NULL);
		return (NOT_A_PROBLEM);
	}
	else
		return (PROBLEM);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;
	char	is_sort;
	int		len_a;

	head_a = NULL;
	head_b = NULL;
	is_sort = NOT_A_PROBLEM;
	if (insert_all_args(argc, argv, &head_a) == PROBLEM
		|| check_duplicate_list(&head_a, &len_a, &is_sort) == PROBLEM)
		exit(1);
	if (head_a == NULL)
		return (0);
	if (read_input(&head_a, &head_b) == PROBLEM)
		return (ft_lstclear(&head_a), ft_lstclear(&head_b)
			, write(2, "Error\n", 7), 1);
	if (is_sort == PROBLEM || head_b != NULL)
		return (ft_lstclear(&head_a), ft_lstclear(&head_b)
			, write(1, "KO\n", 3));
	else
		return (ft_lstclear(&head_a), ft_lstclear(&head_b)
			, write(1, "OK\n", 3));
}
