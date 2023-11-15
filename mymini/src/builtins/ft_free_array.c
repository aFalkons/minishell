/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:34:41 by matteo            #+#    #+#             */
/*   Updated: 2023/11/15 20:22:53 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_array(char **array)
{
	char	*tmp;
	int		i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		tmp = array[i];
		array[i] = NULL;
		free(tmp);
		i++;
	}
	free(array);
}

