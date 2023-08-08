/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:18:44 by matteo            #+#    #+#             */
/*   Updated: 2023/08/08 06:51:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_count_char_split(char const *s, char c)
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
