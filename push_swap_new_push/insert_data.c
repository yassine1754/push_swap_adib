/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:44:57 by yadib             #+#    #+#             */
/*   Updated: 2025/01/28 10:58:26 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_linked_list(char **nums, t_list **head)
{
	int		i;
	t_list	*current;
	int		holder;

	i = 0;
	holder = 0;
	if (*head == NULL)
	{
		if (ft_atoi(nums[i++], &holder) == 'f')
			return ;
		*head = ft_lstnew(holder);
	}
	current = ft_lstlast(*head);
	while (nums[i])
	{
		if (ft_atoi(nums[i++], &holder) == 'f' || current == NULL)
			return (ft_lstclear(head), (void) 0);
		current->next = ft_lstnew(holder);
		current = current->next;
	}
}

char	insert_all_args(int argc, char **argv, t_list **head)
{
	int		i;
	char	**str_nums;

	i = 1;
	while (i < argc)
	{
		str_nums = ft_split(argv[i], ' ');
		if (str_nums[0][0] != 'E')
		{
			create_linked_list(str_nums, head);
			if (*head == NULL)
				return (write(2, "Error\n", 7), free_strings(str_nums), 'F');
		}
		else
		{
			write(2, str_nums[0], 7);
			return (ft_lstclear(head), free(str_nums[0]), free(str_nums), 'F');
		}
		free_strings(str_nums);
		i++;
	}
	return ('S');
}
