/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:24:07 by misidori          #+#    #+#             */
/*   Updated: 2023/12/01 19:23:54 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_copy_array(char **original_array, int size_array)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = ft_calloc((size_array + 1), sizeof(char *));
	if (!new_array)
		return (NULL);
	while (original_array[i])
	{
		new_array[i] = ft_strdup(original_array[i]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
