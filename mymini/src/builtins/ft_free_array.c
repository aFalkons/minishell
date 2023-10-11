/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:34:41 by matteo            #+#    #+#             */
/*   Updated: 2023/10/07 22:44:02 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_array(char **array)
{
	int	i;
	char	*tmp;

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

