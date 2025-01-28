/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoiaXstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:06:05 by yadib             #+#    #+#             */
/*   Updated: 2025/01/24 15:43:32 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	skip_spaces(const char *str, int *skip_spaces_signs)
{
	while (str[*skip_spaces_signs] == 32
		|| (str[*skip_spaces_signs] >= 9 && str[*skip_spaces_signs] <= 13))
		*skip_spaces_signs += 1;
}

static void	skip_check_signs(const char *str,
							int *skip_spaces_signs, short *sign)
{
	if (str[*skip_spaces_signs] == '-' || (str[*skip_spaces_signs] == '+'))
	{
		if (str[*skip_spaces_signs] == '-' )
			*sign *= -1;
		*skip_spaces_signs += 1;
	}
}

static int	convert_str_to_int(const char *str, int *holder,
								int *skip_spaces_signs, short sign)
{
	long long	total_result;

	total_result = 0;
	while ((str[*skip_spaces_signs] >= '0' && str[*skip_spaces_signs] <= '9')
		&& str[*skip_spaces_signs])
	{
		total_result = total_result * 10 + (int)(str[*skip_spaces_signs] - 48);
		*skip_spaces_signs += 1;
		if (total_result * sign > INT_MAX || total_result * sign < INT_MIN)
			return ('f');
	}
	*holder = (int)total_result * sign;
	return ('s');
}

char	ft_atoi(const char *str, int *holder)
{
	int			skip_spaces_signs;
	short		sign;

	skip_spaces_signs = 0;
	sign = 1;
	skip_spaces(str, &skip_spaces_signs);
	skip_check_signs(str, &skip_spaces_signs, &sign);
	return (convert_str_to_int(str, holder, &skip_spaces_signs, sign));
}
