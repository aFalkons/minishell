/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:18:44 by matteo            #+#    #+#             */
/*   Updated: 2023/08/01 16:19:34 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_count_char(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s)
		return (0);
	if (!c)
		return (1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
		{
			counter++;
			if (s[i + 1] == '\0')
				counter--;
		}
		i++;
	}
	return (counter);
}
