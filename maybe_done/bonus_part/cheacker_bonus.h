/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheacker_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:49:54 by yadib             #+#    #+#             */
/*   Updated: 2025/01/28 11:20:25 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEACKER_BONUS_H
# define CHEACKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include "../header.h"

typedef struct s_lines
{
	char			*line;
	struct s_lines	*next;
}	t_lines;

char	ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strdup_b(const char *s1);
size_t	ft_strlen_b(const char *str);
size_t	ft_strlcpy_b(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcat_b(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin_b(char const *s1, char const *s2);
int		ft_strchr_b(const char *s, int c);
char	read_input(t_list **head_a, t_list **head_b);
char	swap_cheacker(t_list **head_a, t_list **head_b, char *line);
char	push_cheacker(t_list **head_a, t_list **head_b, char *line);
char	reverse_cheacker(t_list **head_a, t_list **head_b, char *line);
char	rotate_cheacker(t_list **head_a, t_list **head_b, char *line);
void	ft_lstclear_bonus(t_lines **lst);
t_lines	*ft_lstnew_node(char *line);

#endif