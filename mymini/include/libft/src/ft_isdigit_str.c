/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:49:13 by misidori          #+#    #+#             */
/*   Updated: 2023/11/09 18:15:18 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == true)
			i++;
		else
			return (false);
	}
	return (true);
}
