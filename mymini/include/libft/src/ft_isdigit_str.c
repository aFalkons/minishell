/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:49:13 by misidori          #+#    #+#             */
/*   Updated: 2023/10/04 17:54:13 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_isdigit_str(char *str)
{
	int	i;
	
	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == true)
			i++;
		else
			return (false);
	}
	return (true);
}