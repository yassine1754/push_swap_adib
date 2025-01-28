/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheacker_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:48:49 by yadib             #+#    #+#             */
/*   Updated: 2025/01/28 19:46:38 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheacker_bonus.h"

char	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (NOT_A_PROBLEM);
	return (PROBLEM);
}

char	cheack_all(t_list **head_a, t_list **head_b, char *line)
{
	if (swap_cheacker(head_a, head_b, line) == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else if (rotate_cheacker(head_a, head_b, line) == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else if (reverse_cheacker(head_a, head_b, line) == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else if (push_cheacker(head_a, head_b, line) == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else
		return (PROBLEM);
}

char	check_all_posibility(char *line)
{
	if (ft_strcmp(line, "pb\n") == 'S' || ft_strcmp(line, "pa\n") == 'S')
		return (NOT_A_PROBLEM);
	else if (ft_strcmp(line, "rra\n") == NOT_A_PROBLEM
		|| ft_strcmp(line, "rrb\n") == NOT_A_PROBLEM
		|| ft_strcmp(line, "rrr\n") == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else if (ft_strcmp(line, "ra\n") == NOT_A_PROBLEM
		|| ft_strcmp(line, "rb\n") == NOT_A_PROBLEM
		|| ft_strcmp(line, "rr\n") == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else if (ft_strcmp(line, "sa\n") == NOT_A_PROBLEM
		|| ft_strcmp(line, "sb\n") == NOT_A_PROBLEM
		|| ft_strcmp(line, "ss\n") == NOT_A_PROBLEM)
		return (NOT_A_PROBLEM);
	else
		return (PROBLEM);
}

char	applicate_instruction(t_list **head_a, t_list **head_b,
		t_lines **h_input)
{
	t_lines	*traverse;

	traverse = *h_input;
	while (traverse->line != NULL)
	{
		if (swap_cheacker(head_a, head_b, traverse->line) == NOT_A_PROBLEM)
			traverse = traverse->next;
		else if (reverse_cheacker(head_a, head_b, traverse->line) == 83)
			traverse = traverse->next;
		else if (rotate_cheacker(head_a, head_b, traverse->line) == 83)
			traverse = traverse->next;
		else if (push_cheacker(head_a, head_b, traverse->line) == NOT_A_PROBLEM)
			traverse = traverse->next;
		else
			return (PROBLEM);
	}
	return (NOT_A_PROBLEM);
}

char	read_input(t_list **head_a, t_list **head_b)
{
	t_lines	*h_input;
	t_lines	*traverse;
	int		i;

	i = 0;
	h_input = ft_lstnew_node(get_next_line(0));
	traverse = h_input;
	while (1)
	{
		if (traverse->line && check_all_posibility(traverse->line) == PROBLEM)
			return (ft_lstclear_bonus(&h_input), PROBLEM);
		if (traverse->line == NULL)
		{
			traverse->next = NULL;
			break ;
		}
		traverse->next = ft_lstnew_node(get_next_line(0));
		if (h_input == NULL)
			return (PROBLEM);
		traverse = traverse->next;
	}
	if (applicate_instruction(head_a, head_b, &h_input) == PROBLEM)
		return (ft_lstclear_bonus(&h_input), PROBLEM);
	else
		return (ft_lstclear_bonus(&h_input), NOT_A_PROBLEM);
}
