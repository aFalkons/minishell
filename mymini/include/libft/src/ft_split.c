/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:21:24 by matteo            #+#    #+#             */
/*   Updated: 2023/08/01 16:19:45 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_split(char const *s, char c)
{
	char	**array_strings;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	array_strings = malloc ((ft_count_char(s, c) + 2) * sizeof(char *));
	if (!array_strings)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			array_strings[i++] = ft_substr(s - j, 0, j);
		}
		else
			++s;
	}
	array_strings[i] = 0;
	return (array_strings);
}
