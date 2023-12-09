/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:04:02 by misidori          #+#    #+#             */
/*   Updated: 2023/11/30 17:02:35 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_array(char **array_strings)
{
	int	i;

	i = 0;
	if (!array_strings)
		return (-1);
	while (array_strings[i])
	{
		printf("%s\n", array_strings[i]);
		i++;
	}
	return (1);
}
