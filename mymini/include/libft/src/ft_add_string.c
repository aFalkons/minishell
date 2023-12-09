/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:36 by misidori          #+#    #+#             */
/*   Updated: 2023/12/01 23:31:41 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_add_string(char **array, int *size, const char *string)
{
	char	**new_array;

	new_array = (char **) ft_realloc(array, (*size + 2) * sizeof(char *));
	if (new_array == NULL)
		return (NULL);
	new_array[*size] = ft_strdup(string);
	(*size)++;
	new_array[*size] = NULL;
	return (new_array);
}
