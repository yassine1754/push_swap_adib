/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:01:01 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 16:12:41 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				target_idx;
	struct s_list	*next;
}	t_list;

typedef enum e_result
{
	PROBLEM = 'F',
	NOT_A_PROBLEM = 'S',
	NOT_SORTED = 'N'
}	t_result;

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);
char		**free_strings(char **strings);
void		ft_putstr_fd(char *s);
void		ft_putchar_fd(char c);
size_t		ft_strlen(const char *str);
char		ft_atoi(const char *str, int *holder);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
char		**free_strings(char **strings);
char		check_duplicate_list(t_list **head, int *len_sa, char *is_sort);

#endif 