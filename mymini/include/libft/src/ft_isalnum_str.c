/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:19:39 by misidori          #+#    #+#             */
/*   Updated: 2023/11/09 18:16:38 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_isalnum_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| ((str[i - 1] != '+') && (str[i] == '+') && (str[i + 1] == '='))
			|| (str[i] >= '0' && str[i] <= '9') || (str[i] == '_')
			|| (str[i] == '='))
		{
			i++;
		}
		else
			return (false);
	}
	return (true);
}
