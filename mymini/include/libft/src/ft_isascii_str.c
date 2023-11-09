/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:36 by misidori          #+#    #+#             */
/*   Updated: 2023/11/09 18:12:58 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_isascii_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] <= 127)
		{
			i++;
		}
		else
		{
			return (false);
		}
	}
	return (true);
}
