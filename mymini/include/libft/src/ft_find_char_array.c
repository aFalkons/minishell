/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:18:44 by matteo            #+#    #+#             */
/*   Updated: 2023/11/24 00:20:41 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_find_char_array(char **array, char c)
{
	int	i;
	int	j;

	i = 0;
	if (!array || !c)
		return (0);
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
