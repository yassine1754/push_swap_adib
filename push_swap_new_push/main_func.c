/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:26:35 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 09:05:28 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	int		len_a;
	t_list	*head_a;
	t_list	*head_b;
	char	is_sort;

	head_a = NULL;
	head_b = NULL;
	len_a = 0;
	is_sort = NOT_A_PROBLEM;
	if (argc >= 2)
	{
		if (insert_all_args(argc, argv, &head_a) == PROBLEM
			|| check_duplicate_list(&head_a, &len_a, &is_sort) == PROBLEM)
			exit(1);
		indexing_list(&head_a);
		if (is_sort == NOT_SORTED)
			algo_version_3(&head_a, &head_b, len_a);
	}
	ft_lstclear(&head_a);
}
