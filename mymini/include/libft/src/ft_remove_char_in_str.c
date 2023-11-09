/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char_in_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:43:22 by misidori          #+#    #+#             */
/*   Updated: 2023/11/09 18:04:56 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_remove_char_in_str(char *str, char c)
{
	int	len;
	int	i;
	int	j;

	len = strlen(str);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] != c)
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}
