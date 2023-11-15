/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index_next_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:46:04 by matteo            #+#    #+#             */
/*   Updated: 2023/11/14 21:46:30 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_find_index_next_char(char *str, char c, int i)
{
	i++;

	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
