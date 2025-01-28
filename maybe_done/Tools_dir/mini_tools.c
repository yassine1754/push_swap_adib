/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:57:07 by yadib             #+#    #+#             */
/*   Updated: 2025/01/22 21:13:45 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(const char *s1)
{
	size_t	index_s1;
	size_t	s1_leng;	
	char	*ptr_str;

	index_s1 = 0;
	s1_leng = ft_strlen(s1) + 1;
	ptr_str = malloc(sizeof(char) * (s1_leng));
	if (ptr_str == NULL)
		return (NULL);
	while (s1[index_s1])
	{
		ptr_str[index_s1] = s1[index_s1];
		index_s1++;
	}
	ptr_str[index_s1] = '\0';
	return (ptr_str);
}

static size_t	check_max_length(char const *org_str,
								unsigned int start, size_t len)
{
	if (len >= ft_strlen(org_str + start))
		return (ft_strlen(org_str + start));
	else
		return (len);
}

char	*ft_substr(char const *org_str, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub_string;

	if (org_str == NULL)
		return (NULL);
	index = 0;
	if (start >= ft_strlen(org_str))
		return (ft_strdup(""));
	len = check_max_length(org_str, start, len);
	sub_string = malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	while (index < len)
	{
		sub_string[index] = org_str[index + start];
		index++;
	}
	sub_string[index] = '\0';
	return (sub_string);
}

void	ft_putstr_fd(char *s)
{
	size_t	index;

	if (s == NULL)
		return ;
	index = 0;
	while (s[index])
	{
		ft_putchar_fd(s[index]);
		index++;
	}
}
