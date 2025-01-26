/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:08:24 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 08:47:32 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheacker_bonus.h"

size_t	ft_strlen_b(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat_b(char *dst,
					const char *src, size_t dst_size)
{
	size_t	index;
	size_t	src_ind;
	size_t	result;

	if (dst == NULL && dst_size == 0)
		return (ft_strlen(src));
	src_ind = 0;
	result = ((ft_strlen(dst) + ft_strlen(src)));
	index = ft_strlen(dst);
	if (index >= dst_size)
		return (dst_size + ft_strlen(src));
	while (((index + src_ind) < (dst_size - 1)) && src[src_ind])
	{
		dst[index + src_ind] = src[src_ind];
		src_ind++;
	}
	dst[index + src_ind] = '\0';
	return (result);
}

size_t	ft_strlcpy_b(char *dst,
		const char *src,
		size_t dst_size)
{
	size_t	src_ind;
	size_t	result;

	result = ft_strlen(src);
	src_ind = 0;
	if (dst_size == 0)
		return (result);
	while (src[src_ind] && (src_ind < dst_size - 1))
	{
		dst[src_ind] = src[src_ind];
		src_ind++;
	}
	dst[src_ind] = '\0';
	return (result);
}

char	*ft_strdup_b(const char *s1)
{
	size_t	index_s1;
	size_t	s1_leng;	
	char	*ptr_str;

	if (s1[0] == '\0')
		return (NULL);
	index_s1 = 0;
	s1_leng = ft_strlen_b(s1) + 1;
	ptr_str = malloc((size_t)(sizeof(char) * (s1_leng)));
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

char	*ft_strjoin_b(char const *s1, char const *s2)
{
	size_t		total_leng;
	char		*concatenation_str;
	size_t		s1_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
	{
		concatenation_str = ft_strdup(s1);
		return (free ((char *)s1), concatenation_str);
	}
	s1_len = ft_strlen_b(s1);
	total_leng = s1_len + ft_strlen_b(s2) + 1;
	concatenation_str = malloc((size_t)(sizeof(char) * total_leng));
	if (concatenation_str == NULL)
	{
		free((char *)s1);
		return (NULL);
	}
	ft_strlcpy_b(concatenation_str, s1, ((size_t)s1_len + 1));
	ft_strlcat_b(concatenation_str, s2, total_leng);
	free((char *)s1);
	return (concatenation_str);
}
