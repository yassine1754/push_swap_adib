/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:11:28 by yadib             #+#    #+#             */
/*   Updated: 2025/01/23 17:24:16 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Tools_dir/tools.h"
# include "sorts_tools/algo_lib.h"
# include "Operations/operations.h"

char			insert_all_args(int argc, char **argv, t_list **head);
void			indexing_list(t_list **head);
char			check_is_sort(t_list **head);

#endif
