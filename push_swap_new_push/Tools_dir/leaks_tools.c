/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:17:55 by yadib             #+#    #+#             */
/*   Updated: 2025/01/22 21:13:56 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	**free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (NULL);
}
